#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=1500010;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
int a[N];
int dp[N][3];
vector<int>g[27];
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<=n;i++) t[i]=0;

    for (int i=0;i<26;i++){
        g[i].clear();
    }
    for (int i=0;i<n;i++){
        g[s[i]-'a'].push_back(i);
    }
    for (int i=0;i<26;i++){
        reverse(g[i].begin(),g[i].end());
    }
    string t;cin>>t;
    ll res=inf;
    ll cur=0ll;
    for (int i=0;i<n;i++){
        int c=t[i]-'a';
        for (int j=0;j<c;j++){
            if (!g[j].empty()){
                int ind=g[j].back()-get(g[j].back());
                res=min(res,cur+ind);
            }
        }
        if (g[c].empty()) break;
        int ind=g[c].back()-get(g[c].back());
        cur+=ind;
        upd(n,g[c].back(),1);
        g[c].pop_back();

    }
    if (res==inf) res=-1;
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**




**/