#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int aa; cin >> aa; a.push_back(aa);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (i == 0 || i == n-1 || (a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) ans.push_back(a[i]);
    }
    cout << (int)ans.size() << "\n";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
}
int main(){
    int t=1; cin >> t;
    while (t--) solve();
}