#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

struct Node;

vector<Node> nodes;

struct Node {
    int id, left, right, parent, size;
    int key;

    void recalc() {
        size = 1;
        if (left >= 0) {
            nodes[left].parent = id;
            size += nodes[left].size;
        }
        if (right >= 0) {
            nodes[right].parent = id;
            size += nodes[right].size;
        }
    }
};

void init(int n) {
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].left = nodes[i].right = nodes[i].parent = -1;
        nodes[i].recalc();
    }
}

void rotate(int x) {
    int p = nodes[x].parent;
    int g = nodes[p].parent;
    if (nodes[p].left == x) {
        nodes[p].left = nodes[x].right;
        nodes[x].right = p;
    } else {
        nodes[p].right = nodes[x].left;
        nodes[x].left = p;
    }
    nodes[p].recalc();
    nodes[x].recalc();
    if (g >= 0) {
        if (nodes[g].left == p) nodes[g].left = x; else nodes[g].right = x;
        nodes[g].recalc();
    } else {
        nodes[x].parent = -1;
    }
}

void splay(int x) {
    while (nodes[x].parent >= 0) {
        int p = nodes[x].parent;
        int g = nodes[p].parent;
        if (g == -1) {
            rotate(x);
            return;
        }
        if (x == nodes[p].right && p == nodes[g].right || x == nodes[p].left && p == nodes[g].left) {
            rotate(p);
            rotate(x);
        } else {
            rotate(x);
            rotate(x);
        }
    }
}

int max(int x) {
    while (nodes[x].right >= 0) {
        x = nodes[x].right;
    }
    splay(x);
    return x;
}

int merge(int x, int y) {
    if (x == -1) {
        return y;
    }
    x = max(x);
    nodes[x].right = y;
    nodes[x].recalc();
    return x;
}

pair<int, int> split_after(int x) {
    splay(x);
    int y = nodes[x].right;
    if (y >= 0) {
        nodes[y].parent = -1;
        nodes[x].right = -1;
        nodes[x].recalc();
    }
    return {x, y};
}

pair<int, int> split_before(int x) {
    splay(x);
    int y = nodes[x].left;
    if (y >= 0) {
        nodes[y].parent = -1;
        nodes[x].left = -1;
        nodes[x].recalc();
    }
    return {y, x};
}

int get_size(int x) {
    if (x == -1) return 0;
    return nodes[x].size;
}

int find_k(int x, int k) {
    if (k >= get_size(x)) return -1;
    int l = get_size(nodes[x].left);
    if (k < l) {
        return find_k(nodes[x].left, k);
    } else if (k == l) {
        return x;
    } else return find_k(nodes[x].right, k - l - 1);
}

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    scanf("%d%d", &n, &m);

    init(n);

    int root = 0;
    for (int i = 1; i < n; i++) {
        root = merge(root, i);
    }

    vector<bool> used(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int c = find_k(root, y - 1);
        if (nodes[c].key == 0) {
            if (used[x]) {
                cout << "-1\n";
                return 0;
            }
            used[x] = true;
            nodes[c].key = x;
        }
        if (nodes[c].key != x) {
            cout << "-1\n";
            return 0;
        }
        int ll = split_before(c).first;
        int rr = split_after(c).second;
        root = merge(c, merge(ll, rr));
    }

    int j = 1;
    for (int i = 0; i < n; i++) {
        if (nodes[i].key == 0) {
            while (used[j]) j++;
            nodes[i].key = j;
            used[j] = true;
        }
        cout << nodes[i].key << " ";
    }

    return 0;
}