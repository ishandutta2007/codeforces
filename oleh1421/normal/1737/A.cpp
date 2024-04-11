#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ld inf=1e18;
const int N=500010;
void solve(){
    vector<int>cnt(26,0);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for (auto i:s){
        cnt[i-'a']++;
    }
    string ans="";
    for (int it=1;it<=k;it++){
        int need=n/k;
        int mex=-1;
        int last=-1;
        for (int i=0;i<26;i++){
            if (need==0) break;
            last=i;
            if (cnt[i]){
                cnt[i]--;
                need--;
            } else {
                if (mex==-1) mex=i;
            }
        }
        if (mex==-1) mex=last+1;
        ans+=char(mex+'a');
    }
    cout<<ans<<'\n';

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**


**/