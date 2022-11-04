#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

struct Data {
    int l, r;
    int pos;
}v[MAXN + 1];

bool cmp(Data a, Data b) {
    if(a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].pos = i;
    }
    sort(v + 1, v + n + 1, cmp);
    int id = -1, mxr = 0;
    for(i = 1; i <= n; i++) {
        if(id > -1 && mxr >= v[i].r) {
            cout << v[i].pos << " " << v[id].pos;
            return 0;
        }
        if(v[i].r > mxr) {
            mxr = v[i].r;
            id = i;
        }
    }
    cout << -1 << " " << -1;
    //cin.close();
    //cout.close();
    return 0;
}