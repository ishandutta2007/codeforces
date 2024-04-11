//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=1000000007ll;
const int A=1000100;
int pref[N];
int suf[N];
void solve(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    pref[0]=-1;
    for (int i=0;i<t.size();i++){
        pref[i+1]=pref[i]+1;
        while (s[pref[i+1]]!=t[i]) pref[i+1]++;
    }
    suf[t.size()+1]=(int)s.size();
    for (int i=(int)t.size()-1;i>=0;i--){
        suf[i+1]=suf[i+2]-1;

        while (s[suf[i+1]]!=t[i]) suf[i+1]--;
//        cout<<i+1<<" "<<suf[i+1]<<endl;
    }
    int res=0;
    for (int i=1;i<t.size();i++){
        res=max(res,suf[i+1]-pref[i]);
    }
    cout<<res<<endl;


}
int32_t main()
{
//    srand(time(NULL));
//    freopen("subset.in","r",stdin);
//    freopen("subset.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*

4 3 5

*/