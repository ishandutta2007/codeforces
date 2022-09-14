//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//const ll mod=1000000007ll;
using namespace std;
#define endl '\n'
const int N=200010;
const int L=31;
int a[N];
vector<int>g[L];
void solve(){
    string s,t;cin>>s>>t;
    for (int i=0;i<=26;i++) g[i].clear();
    for (int i=0;i<s.size();i++){
        g[s[i]-'a'].push_back(i);
    }
    int pos=-1;
    int cnt=0;
    for (int i=0;i<t.size();i++){
        if (g[t[i]-'a'].empty()){
            cout<<"-1\n";
            return;
        }
        auto nxt=upper_bound(g[t[i]-'a'].begin(),g[t[i]-'a'].end(),pos);
        if (nxt==g[t[i]-'a'].end()){
            cnt++;
            pos=-1;
            nxt=upper_bound(g[t[i]-'a'].begin(),g[t[i]-'a'].end(),pos);

        }
        pos=*nxt;
    }
    if (pos!=-1) cnt++;
    cout<<cnt<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}