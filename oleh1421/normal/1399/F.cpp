#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=3010;
int l[N],r[N];
vector<int>g[N*2];
int dp[N*N*2];
int calc(int a,int b){
    if (a>b) return 0;
    int cur=b*(b-1)/2+a;
    if (dp[cur]!=-1) return dp[cur];
    int add=0;
    for (int i:g[a]){
        if (i==b) add++;
    }
    int res=calc(a+1,b);
    for (int i:g[a]){
        if (i<b) res=max(res,calc(a,i)+calc(i+1,b));
    }
    res+=add;
    return dp[cur]=res;
}
void solve(){
    int n;cin>>n;
    set<int>st;
    map<int,int>mp;
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        st.insert(l[i]);
        st.insert(r[i]);
    }
    int cnt=0;
    for (int x:st){
        mp[x]=++cnt;
    }
    for (int i=1;i<=n;i++){
        l[i]=mp[l[i]];
        r[i]=mp[r[i]];
        g[l[i]].push_back(r[i]);
    }
    for (int i=0;i<=cnt*(cnt+1)/2;i++) dp[i]=-1;
    cout<<calc(1,cnt)<<endl;
    for (int i=1;i<=cnt;i++) g[i].clear();
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
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1
2 100
1 2 409 2
**/