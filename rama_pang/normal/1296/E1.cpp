// Based on E2 Code
#include <bits/stdc++.h>
using namespace std;

mt19937 rng((uint32_t) chrono::high_resolution_clock::now().time_since_epoch().count());

const int ALP = 27;

struct TreapNode {
    int prior, val[ALP] = {};
    int flip, sum[ALP] = {};
    int sz, key;
    TreapNode *l, *r;

    TreapNode() {
        prior = rng();
        flip = 0;
        sz = 1;
        l = r = NULL;
        key = 0;
        for (int i = 0; i < ALP; i++) {
            val[i] = sum[i] = 0;
        }
    }

};

using tnode = TreapNode;
using pt = tnode*;

int sz(pt t) {
    return t ? t->sz : 0;
}

int sum(pt t, int i) {
    return t ? t->sum[i] : 0;
}

void upd_sz(pt t) {
    if (t) {
        t->sz = 1 + sz(t->l) + sz(t->r);
        for (int i = 1; i < ALP; i++) {
            t->sum[i] = t->val[i] + sum(t->l, i) + sum(t->r, i);
        }
    }
}

void prop(pt t) { // propagate
    if (!t || !t->flip) { return; }
    t->flip = 0;
    if (t->l) { t->l->flip ^= 1; }
    if (t->r) { t->r->flip ^= 1; }
    swap(t->l, t->r);
}

void split(pt t, pt &l, pt &r, int pos) { // left = [0, pos]
    if (!t) { return void(l = r = NULL); }
    prop(t);
    if (pos < t->key) {
        split(t->l, l, t->l, pos), r = t;
    } else {
        split(t->r, t->r, r, pos), l = t;
    }
    upd_sz(t);
}

void merge(pt &t, pt l, pt r) {
    prop(l), prop(r);
    if (!l || !r) {
        t = l ? l : r;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r), t = l;
    } else {
        merge(r->l, l, r->l), t = r;
    }
    upd_sz(t);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string t = s;
    sort(begin(t), end(t));

    deque<int> id[ALP]; // max answer is 26, 1 for each letter

    for (int i = 0; i < n; i++) {
        id[t[i] - 'a'].emplace_back(i);
    }
    vector<int> where(n, -1);
    for (int i = 0; i < n; i++) {
        where[i] = id[s[i] - 'a'].front();
        id[s[i] - 'a'].pop_front();
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << where[i] << "\n";
    // }

    int ans = 0;
    vector<int> color(n, 0);


    pt T = NULL;

    for (int i = 0; i < n; i++) {
        pt k = new tnode();
        pt a, b;
        split(T, a, b, where[i]);

        for (int j = 1; j < ALP; j++) {
            if (sum(b, j) == 0) {
                ans = max(ans, j);
                color[i] = j;
                break;
            }
        }
        
        k->val[color[i]] = 1;
        k->key = where[i];
        

        merge(T, a, k);
        merge(T, T, b);

        // for (int j = 1; j < 5; j++) {
        //     cout << sum(T, j) << " \n"[j == 4];
        // }

    }

    if (ans <= 2) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << (color[i] - 1);
        }
        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }
}