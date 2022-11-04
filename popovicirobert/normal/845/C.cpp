#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 200000;

struct Data {
    int val;
    bool t;
    bool operator <(const Data &other) const {
         return val < other.val;
    }
}v[2 * MAXN + 1];

int R[2 * MAXN + 1];

int sp[2 * MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, l, r;
    ios::sync_with_stdio(false);
    cin >> n;
    int sz = 0;
    for(i = 1; i <= n; i++) {
        cin >> l >> r;
        v[++sz] = {l, 0};
        v[++sz] = {r + 1, 1};
    }
    sort(v + 1, v + sz + 1);
    int val = 0;
    v[0].val = -1;
    for(i = 1; i <= sz; i++) {
        if(v[i].val == v[i - 1].val)
            R[i] = R[i - 1];
        else {
            val++;
            R[i] = val;
        }
        if(v[i].t == 0)
            sp[R[i]]++;
        else
            sp[R[i]]--;
    }
    int mx = 0;
    for(i = 1; i <= sz; i++) {
         sp[i] += sp[i - 1];
         mx = max(mx, sp[i]);
    }
    if(mx <= 2)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}