#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> S[500500];
int ans[500500];

bool comp(pair<int, int> x, pair<int, int> y){
    ll tmp1 = (ll)x.first*y.second, tmp2 = (ll)x.second*y.first;
    return tmp1==tmp2;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    S[0] = {0, 0};
    for (int i=1;i<=n;i++){
        if (s[i-1]=='D') S[i] = make_pair(S[i-1].first+1, S[i-1].second);
        else S[i] = make_pair(S[i-1].first, S[i-1].second+1);
    }
    fill(ans, ans+n+1, 1);
    for (int i=2;i<=n;i++){
        auto tmp = S[i];
        int g = __gcd(tmp.first, tmp.second);
        tmp.first /= g, tmp.second /= g;
        int s = tmp.first+tmp.second;
        for (int j=i-s;j>0;j-=s){
            if (comp(S[j], tmp)){
                ans[i] = max(ans[i], ans[j]+1);
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}