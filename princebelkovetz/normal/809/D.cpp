#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int N = 2e5, mod = 1e9 + 7, p = 464;

struct node {
    node* l, * r;
    int x, y, add, sz;
    node(int x) : x(x) {
        y = (rand() << 15) + rand();
        l = r = nullptr;
        add = 0, sz = 1;
    }
};

void push(node* root) {
    root->x += root->add;
    if (root->l) root->l->add += root->add;
    if (root->r) root->r->add += root->add;
    root->add = 0;
}

int getsz(node* root) {
    return root ? root->sz : 0;
}

void upd(node* root) {
    root->sz = getsz(root->l) + 1 + getsz(root->r);
}

pair <node*, node*> split(node* root, int x) {
    if (root == nullptr) return { root, root };
    push(root);
    if (root->x < x) {
        auto get = split(root->r, x);
        root->r = get.first;
        upd(root);
        return { root, get.second };
    }
    else {
        auto get = split(root->l, x);
        root->l = get.second;
        upd(root);
        return { get.first, root };
    }
}

pair <node*, node*> splitBySize(node* root, int k) {
    if (root == nullptr) return { root, root };
    push(root);
    if (getsz(root->l) >= k) {
        auto get = splitBySize(root->l, k);
        root->l = get.second;
        upd(root);
        return { get.first, root };
    }
    else {
        auto get = splitBySize(root->r, k - getsz(root->l) - 1);
        root->r = get.first;
        upd(root);
        return { root, get.second };
    }
}

node* merge(node* L, node* R) {
    if (L == nullptr) return R;
    if (R == nullptr) return L;
    push(L), push(R);
    if (L->y < R->y) {
        L->r = merge(L->r, R);
        upd(L);
        return L;
    }
    else {
        R->l = merge(L, R->l);
        upd(R);
        return R;
    }
}

void print(node* root) {
    if (!root) return;
    push(root);
    print(root->l);
    cout << root->x << ' ';
    print(root->r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;

    node* root = new node(0);
    for (int i = 0; i < n; ++i)
        root = merge(root, new node(mod));

    for (int i = 1, l, r; i <= n; ++i) {
        cin >> l >> r;
        auto get = split(root, l);
        auto get2 = split(get.second, r);
        get.first = merge(get.first, new node(l));
        get2.second = splitBySize(get2.second, 1).second;
        if (get2.first) get2.first->add++;
        root = merge(get.first, get2.first);
        root = merge(root, get2.second);
    }
    cout << getsz(split(root, mod).first) - 1 << '\n';
    return 0;
}