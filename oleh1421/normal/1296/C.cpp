#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
const int N=200010;
map<pair<int,int>,int>mp;
void solve(){
    mp.clear();
    int n;cin>>n;
    mp[{0,0}]=0;
    int cnt1=0;
    int cnt2=0;
    int L=-1;
    int R=1000000001;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='R') cnt1++;
        else if (c=='L') cnt1--;
        else if (c=='U') cnt2++;
        else cnt2--;
        pair<int,int>cur={cnt1,cnt2};
        if (mp.find(cur)!=mp.end()){
            int l=mp[cur]+1;
            int r=i;
            if (r-l<R-L){
                L=l;
                R=r;
            }
        }
        mp[cur]=i;
    }
    if (L>0) cout<<L<<" "<<R<<endl;
    else cout<<"-1\n";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}