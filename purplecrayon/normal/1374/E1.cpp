#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

ll a[MAXN];

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a, b, ab;
    for (int i = 0; i < n; i++){
        int t, aa, bb; cin >> t >> aa >> bb;
        if (aa&&bb) ab.push_back(t);
        else if (aa) a.push_back(t);
        else if (bb) b.push_back(t);
    }
    sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(ab.begin(), ab.end());
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end()); reverse(ab.begin(), ab.end());
    if ((int)(a.size()+ab.size()) < k || (int)(b.size()+ab.size()) < k) { cout << "-1\n"; return; }
    int al=k, bl=k;
    vector<int> taken;
    ll ans = 0;
    while (al||bl){
        if (ab.size()) { taken.push_back(ab.back()); ans += ab.back(); ab.pop_back(); al--, bl--;  continue; }
        taken.push_back(a.back()+b.back());
        ans += a.back(); a.pop_back(); al--;
        ans += b.back(); b.pop_back(); bl--;
    }
    sort(taken.begin(), taken.end());
    for (int i = k-1; i >= 0; i--){
        if (a.size() && b.size() && a.back()+b.back() < taken[i]) ans+=a.back()+b.back()-taken[i], a.pop_back(), b.pop_back();
    }
    cout << ans << "\n";
}
int main(){
    int t=1;// cin >> t;
    while (t--) solve();
}