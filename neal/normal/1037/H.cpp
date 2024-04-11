#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string str;
vector<int> suffix, suf_rank;

void suffix_array(bool large_alphabet = false) {
    suffix.resize(N);

    for (int i = 0; i < N; i++)
        suffix[i] = i;

    // Sort each suffix by the first character.
    if (large_alphabet) {
        sort(suffix.begin(), suffix.end(), [&](int a, int b) {
            return str[a] < str[b];
        });
    } else {
        vector<int> freq(256, 0);

        for (int i = 0; i < N; i++)
            freq[str[i]]++;

        for (int c = 1; c < 256; c++)
            freq[c] += freq[c - 1];

        for (int i = 0; i < N; i++)
            suffix[--freq[str[i]]] = i;
    }

    // Compute the rank of each suffix. Tied suffixes share the same rank.
    suf_rank.resize(N);
    suf_rank[suffix[0]] = 0;

    for (int i = 1; i < N; i++)
        suf_rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? suf_rank[suffix[i - 1]] : i;

    vector<int> next_index(N);
    vector<int> values(N);
    bool done = false;

    for (int len = 1; len < N && !done; len *= 2) {
        // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
        // suffix that comes len characters after the current suffix.
        for (int i = 0; i < N; i++)
            next_index[i] = i;

        // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
        for (int i = N - len; i < N; i++)
            values[next_index[suf_rank[i]]++] = i;

        for (int i = 0; i < N; i++) {
            int prev = suffix[i] - len;

            if (prev >= 0)
                values[next_index[suf_rank[prev]]++] = prev;
        }

        swap(suffix, values);

        // Compute the rank array for 2 * len.
        values[suffix[0]] = 0;
        done = true;

        for (int i = 1; i < N; i++) {
            int s = suffix[i], prev = suffix[i - 1];

            if (s + len < N && prev + len < N &&
                suf_rank[s] == suf_rank[prev] && suf_rank[s + len] == suf_rank[prev + len]) {
                values[s] = values[prev];
                done = false;
            } else {
                values[s] = i;
            }
        }

        swap(suf_rank, values);
    }
}


struct segment_change {
    int value;

    segment_change(int _value = N) : value(_value) {}

    void reset() {
        value = N;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(min(value, other.value));
    }
};

struct segment {
    int minimum;

    segment() : minimum(N) {}

    void apply(int start, int end, const segment_change &change) {
        minimum = min(minimum, change.value);
    }

    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct persistent_seg_tree {
    static const bool LAZY_PROPAGATION = false;

    struct node {
        segment seg;
        segment_change change;
        int left, right;
    };

    int tree_n;
    vector<node> tree;

    persistent_seg_tree(int n = 0, int reserve_size = 0) {
        tree_n = 0;

        if (n > 0)
            init(n, reserve_size);
    }

    void init(int n, int reserve_size = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        if (reserve_size > 0)
            tree.reserve(reserve_size);

        tree.assign(2 * tree_n, node());

        for (int i = 1; i < tree_n; i++) {
            tree[i].left = 2 * i;
            tree[i].right = 2 * i + 1;
        }
    }

    int& left(int position) { return tree[position].left; }
    int& right(int position) { return tree[position].right; }

    int make_copy(int position) {
        assert(0 <= position && position < (int) tree.size());
        tree.push_back(tree[position]);
        return tree.size() - 1;
    }

    void push_down(int position, int start, int mid, int end) {
        tree[left(position)].seg.apply(start, mid, tree[position].change);
        tree[right(position)].seg.apply(mid, end, tree[position].change);
        tree[left(position)].change = tree[left(position)].change.combine(tree[position].change);
        tree[right(position)].change = tree[right(position)].change.combine(tree[position].change);
        tree[position].change.reset();
    }

    void query_tree(int position, int start, int end, int a, int b, segment &answer, const segment_change &propagate) {
        if (a <= start && end <= b) {
            segment seg = tree[position].seg;
            seg.apply(start, end, propagate);
            answer.join(seg);
            return;
        }

        if (left(position) == -1 || right(position) == -1)
            return;

        int mid = (start + end) / 2;
        segment_change next_propagate = tree[position].change.combine(propagate);
        if (a < mid) query_tree(left(position), start, mid, a, b, answer, next_propagate);
        if (b > mid) query_tree(right(position), mid, end, a, b, answer, next_propagate);
    }

    segment query(int root, int a, int b) {
        segment answer;
        query_tree(root, 0, tree_n, a, b, answer, segment_change());
        return answer;
    }

    // Directly assigning `left(position) = make_copy(left(position))` results in segmentation faults, because the
    // address for `left(position)` can be computed before calling `make_copy`, which may reallocate `tree`.
    void set_left(int position, int result) { left(position) = result; }
    void set_right(int position, int result) { right(position) = result; }

    int update_tree(int position, int start, int end, int a, int b, const segment_change &change, bool needs_copy) {
        if (needs_copy)
            position = make_copy(position);

        if (a <= start && end <= b) {
            tree[position].seg.apply(start, end, change);
            tree[position].change = tree[position].change.combine(change);
            return position;
        }

        if (left(position) == -1 || right(position) == -1)
            return position;

        int mid = (start + end) / 2;

        if (LAZY_PROPAGATION) {
            set_left(position, make_copy(left(position)));
            set_right(position, make_copy(right(position)));
            push_down(position, start, mid, end);
            needs_copy = false;
        }

        if (a < mid) set_left(position, update_tree(left(position), start, mid, a, b, change, needs_copy));
        if (b > mid) set_right(position, update_tree(right(position), mid, end, a, b, change, needs_copy));
        tree[position].seg.join(tree[left(position)].seg, tree[right(position)].seg);
        return position;
    }

    int update(int root, int a, int b, const segment_change &change) {
        assert(LAZY_PROPAGATION || b - a <= 1);
        return update_tree(root, 0, tree_n, a, b, change, true);
    }
};


persistent_seg_tree tree;
vector<int> tree_roots;

template<typename BooleanFunc>
int binary_search(int low, int high, BooleanFunc &&works) {
    // Finds the smallest index i where works(i) is true.
    while (low < high) {
        int mid = (low + high) / 2;

        if (works(mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

string query(int L, int R, string &X) {
    int len = X.size();
    int suf_low = 0, suf_high = N;

    int best_match = -1;
    char diff_char;

    for (int match = 0; match <= len; match++) {
        int start = binary_search(suf_low, suf_high, [&](int index) {
            return suffix[index] + match < N ? str[suffix[index] + match] >= X[match] : match == len;
        });

        int end = binary_search(start, suf_high, [&](int index) {
            return suffix[index] + match < N && str[suffix[index] + match] > X[match];
        });

        int answer = tree.query(tree_roots[end], L, R - match).minimum;

        if (answer < suf_high) {
            best_match = match;
            diff_char = str[suffix[answer] + match];
        }

        suf_low = start;
        suf_high = end;

        if (suf_low >= suf_high)
            break;
    }

    return best_match == -1 ? "-1" : X.substr(0, best_match) + diff_char;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    N = str.size();
    suffix_array();

    tree.init(N);
    tree_roots.assign(N + 1, 1);

    for (int bottom = N - 1; bottom >= 0; bottom--)
        tree_roots[bottom] = tree.update(tree_roots[bottom + 1], suffix[bottom], suffix[bottom] + 1, bottom);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int L, R;
        string X;
        cin >> L >> R >> X;
        L--;
        cout << query(L, R, X) << '\n';
    }
}