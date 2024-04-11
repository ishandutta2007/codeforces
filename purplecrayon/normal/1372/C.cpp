#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

int n, a[MAXN];

void solve(){
    int n; cin >> n; bool b = true;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i], b &= (a[i] == i);
    if (b){
        cout << "0\n"; return;
    }
    int lp = 0, rp = n-1;
    for (; lp < n && a[lp]==lp; lp++);
    for (; rp >= 0 && a[rp]==rp; rp--);
    for (int i = lp; i <= rp; i++) if (a[i] == i) {
        cout << "2\n"; return;
    }
    cout << "1\n"; return;
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}