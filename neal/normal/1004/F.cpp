#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int PREFIX_SUFFIX_MAX = 21;

int X;

struct seg_tree_node {
    int start, end;

    long long count;

    // pairs of {index from end, bitwise or value}
    int P, S;
    pair<int, int> prefix[PREFIX_SUFFIX_MAX], suffix[PREFIX_SUFFIX_MAX];

    seg_tree_node() : start(-1), end(-1), count(0), prefix({{0, 0}}), suffix({{0, 0}}) {}

    void apply(int value) {
        assert(end - start == 1);
        count = value >= X ? 1 : 0;
        prefix[0] = {0, value};
        suffix[0] = {0, value};
        P = S = 1;
    }

    void combine_prefixes(int &G, pair<int, int> *goal, int P1, const pair<int, int> *prefix1, int P2, const pair<int, int> *prefix2, int length) {
        G = 0;

        for (int i = 0; i < P1; i++)
            goal[G++] = prefix1[i];

        int full = G == 0 ? 0 : goal[G - 1].second;

        for (int i = 0; i < P2; i++) {
            int together = full | prefix2[i].second;

            if (together != full) {
                goal[G++] = {prefix2[i].first + length, together};
                full = together;
            }
        }
    }

    void join_nodes(seg_tree_node &a, seg_tree_node &b) {
        if (a.start == -1) {
            *this = b;
            return;
        } else if (b.start == -1) {
            *this = a;
            return;
        }

        assert(a.start < a.end && a.end == b.start && b.start < b.end);
        int a_length = a.end - a.start;
        int b_length = b.end - b.start;

        start = a.start;
        end = b.end;
        count = a.count + b.count;
        combine_prefixes(P, prefix, a.P, a.prefix, b.P, b.prefix, a_length);
        combine_prefixes(S, suffix, b.S, b.suffix, a.S, a.suffix, b_length);

        // Compute the cross-count
        a.suffix[a.S].first = a_length;
        b.prefix[b.P].first = b_length;

        for (int i = a.S - 1, j = 0; i >= 0; i--) {
            while (j < b.P && (a.suffix[i].second | b.prefix[j].second) < X)
                j++;

            int a_len = a.suffix[i + 1].first - a.suffix[i].first;
            int b_len = b_length - b.prefix[j].first;
            count += (long long) a_len * b_len;
        }
    }
};

struct seg_tree {
    int pow2_n;
    vector<seg_tree_node> tree;

    seg_tree(int n = 0) {
        pow2_n = 0;

        if (n > 0)
            init(n);
    }

    void init(int n) {
        pow2_n = 1;

        while (pow2_n < n)
            pow2_n *= 2;

        tree.clear();
        tree.resize(2 * pow2_n);
        set_start_and_end(1, 0, pow2_n);
    }

    void set_start_and_end(int position, int start, int end) {
        tree[position].start = start;
        tree[position].end = end;

        if (position < pow2_n) {
            int mid = (start + end) / 2;
            set_start_and_end(2 * position, start, mid);
            set_start_and_end(2 * position + 1, mid, end);
        }
    }

    seg_tree_node query_tree(int position, int a, int b) {
        int start = tree[position].start;
        int end = tree[position].end;
        int mid = (start + end) / 2;

        if (a <= start && end <= b)
            return tree[position];
        else if (b <= mid)
            return query_tree(2 * position, a, b);
        else if (a >= mid)
            return query_tree(2 * position + 1, a, b);

        seg_tree_node left_half = query_tree(2 * position, a, b);
        seg_tree_node right_half = query_tree(2 * position + 1, a, b);
        seg_tree_node answer;
        answer.join_nodes(left_half, right_half);
        return answer;
    }

    void update_index(int index, int value) {
        for (int position = pow2_n + index; position > 0; position /= 2)
            if (position >= pow2_n)
                tree[position].apply(value);
            else
                tree[position].join_nodes(tree[2 * position], tree[2 * position + 1]);
    }

    void init_array(const vector<int> &values) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[pow2_n + i].apply(values[i]);

        for (int position = pow2_n - 1; position > 0; position--)
            tree[position].join_nodes(tree[2 * position], tree[2 * position + 1]);
    }
};


int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;
    seg_tree tree(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++)
        cin >> values[i];

    tree.init_array(values);

    for (int i = 0; i < M; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        a--;

        if (type == 1)
            tree.update_index(a, b);
        else
            cout << tree.query_tree(1, a, b).count << '\n';
    }

    return 0;
}