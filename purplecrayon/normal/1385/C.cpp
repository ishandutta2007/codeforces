#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+10;

int a[MAXN];

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int rptr = n-1;
    while (rptr > 0 && a[rptr-1] >= a[rptr]) rptr--;
    int lptr = rptr-1;
    while (lptr > 0 && a[lptr-1] <= a[lptr]) lptr--;
    cout << max(lptr, 0) << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}