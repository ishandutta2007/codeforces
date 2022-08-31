#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct seg_tree_node {
    int sum;

    int change_mult;
    int change_add;

    seg_tree_node(int _sum = 0, int _change_mult = 1, int _change_add = 0) {
        sum = _sum;
        change_mult = _change_mult;
        change_add = _change_add;
    }

    seg_tree_node merge(const seg_tree_node &other) const {
        return seg_tree_node((sum + other.sum) % MOD);
    }

    void apply(int start, int end, int to_mult, int to_add) {
        sum = ((long long) sum * to_mult + (long long) (end - start) * to_add) % MOD;
        change_mult = (long long) change_mult * to_mult % MOD;
        change_add = ((long long) change_add * to_mult + to_add) % MOD;
    }

    void reset_changes() {
        change_mult = 1;
        change_add = 0;
    }
};

struct seg_tree {
    int n;
    int pow2_n;
    seg_tree_node *tree;

    seg_tree(int _n = 0) {
        n = 0;
        pow2_n = 0;
        tree = NULL;

        if (_n > 0) {
            init(_n);
        }
    }

    void init(int _n) {
        n = _n;
        pow2_n = 1;

        while (pow2_n < n) {
            pow2_n *= 2;
        }

        if (tree != NULL) {
            delete[] tree;
        }

        tree = new seg_tree_node[2 * pow2_n];
    }

    ~seg_tree() {
        if (tree != NULL) {
            delete[] tree;
        }
    }

    void push_down(int position, int start, int mid, int end) {
        int to_mult = tree[position].change_mult;
        int to_add = tree[position].change_add;

        tree[2 * position].apply(start, mid, to_mult, to_add);
        tree[2 * position + 1].apply(mid, end, to_mult, to_add);
        tree[position].reset_changes();
    }

    seg_tree_node query_tree(int position, int start, int end, int a, int b) {
        if (a <= start && end <= b) {
            return tree[position];
        }

        if (position >= pow2_n || start >= b || a >= end) {
            return seg_tree_node();
        }

        int mid = (start + end) / 2;
        push_down(position, start, mid, end);
        seg_tree_node left_half = query_tree(2 * position, start, mid, a, b);
        seg_tree_node right_half = query_tree(2 * position + 1, mid, end, a, b);
        return left_half.merge(right_half);
    }

    seg_tree_node query(int a, int b) {
        return query_tree(1, 0, pow2_n, a, b);
    }

    void update_tree(int position, int start, int end, int a, int b, int to_mult, int to_add) {
        if (a <= start && end <= b) {
            tree[position].apply(start, end, to_mult, to_add);
            return;
        }

        if (position >= pow2_n || start >= b || a >= end) {
            return;
        }

        int mid = (start + end) / 2;
        push_down(position, start, mid, end);
        update_tree(2 * position, start, mid, a, b, to_mult, to_add);
        update_tree(2 * position + 1, mid, end, a, b, to_mult, to_add);
        tree[position] = tree[2 * position].merge(tree[2 * position + 1]);
    }

    void update_mult(int a, int b, int value) {
        update_tree(1, 0, pow2_n, a, b, value, 0);
    }

    void update_add(int a, int b, int value) {
        update_tree(1, 0, pow2_n, a, b, 1, value);
    }
};

int N, Q;
map<int, set<pair<int, int> > > element_ranges;
seg_tree tree;

template<typename T>
typename set<T>::iterator prev(typename set<T>::iterator it) {
    return --it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    tree.init(N);

    for (int q = 0; q < Q; q++) {
        int q_type, a, b, x;
        cin >> q_type >> a >> b;
        a--;

        if (q_type == 1) {
            cin >> x;

            set<pair<int, int> > &ranges = element_ranges[x];
            vector<pair<int, int> > multiply;
            vector<pair<int, int> > increment;
            auto it = ranges.lower_bound(make_pair(a, -1));
            int current = a;

            while (it != ranges.end() && it->first <= b) {
                // cerr << "Erasing " << it->first << ' ' << it->second << '\n';

                if (current != it->first) {
                    pair<int, int> section = make_pair(current, it->first);
                    (it->second == -1 ? multiply : increment).push_back(section);
                    current = it->first;
                }

                it++;
                ranges.erase(prev(it));
                // cerr << "Afterward at " << it->first << ' ' << it->second << '\n';
            }

            // cerr << "Currently at " << it->first << ' ' << it->second << '\n';

            if (it == ranges.begin() || prev(it)->second == -1) {
                ranges.insert(it, make_pair(a, +1));
            }

            if (it == ranges.end() || it->second == +1) {
                ranges.insert(it, make_pair(b, -1));
                increment.push_back(make_pair(current, b));
            } else {
                multiply.push_back(make_pair(current, b));
            }

            // for (it = ranges.begin(); it != ranges.end(); it++) {
            //     cerr << it->first << ' ' << it->second << '\n';
            // }

            // cerr << '\n';

            for (pair<int, int> p : multiply) {
                tree.update_mult(p.first, p.second, 2);
                // cerr << "Mult " << p.first << " " << p.second << "\n";
            }

            for (pair<int, int> p : increment) {
                tree.update_add(p.first, p.second, 1);
                // cerr << "Add " << p.first << " " << p.second << "\n";
            }
        } else {
            cout << tree.query(a, b).sum << '\n';
        }
    }

    return 0;
}