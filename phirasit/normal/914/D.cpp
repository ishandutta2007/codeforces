#include <algorithm>
#include <iostream>

using namespace std;

const int N = 500010;

struct node {

    int l, r;
    int gcd;
    node *left, *right;

    node(int l, int r) :
        l(l), r(r), gcd(0),
        left(l < r ? new node(l, (l+r)/2) : nullptr),
        right(l < r ? new node((l+r)/2+1, r) : nullptr) {}

    void update(int idx, int val) {
        if (l >= r) {
            gcd = val;
        } else {
            (idx <= left->r ? left : right)->update(idx, val);
            gcd = __gcd(left->gcd, right->gcd);
        }
    }

    int query(int l, int r) {
        if (r < this->l || this->r < l) return 0;
        if (l <= this->l && this->r <= r) return gcd;
        return __gcd(left->query(l, r), right->query(l, r));
    }

    bool check(int l, int r, int x) {
        if (r < this->l || this->r < l) return true;
        if (this->l >= this->r) return true;
             
        if (l > left->r || left->query(l, left->r) % x == 0) 
            return right->check(l, r, x);
        if (r < right->l || right->query(right->l, r) % x == 0) 
            return left->check(l, r, x);
        return false;
    }
};

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    node* head = new node(1, n);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        head->update(i, val);
    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;

            cout << (head->check(l, r, x) ? "YES" : "NO") << endl;
        } else {
            int idx, val;
            cin >> idx >> val;

            head->update(idx, val);
        }
    }

    return 0;
}