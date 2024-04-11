#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
int a[13][10001];
int x[2001];
int n,m;
int r[20001];
int maxx[20001];
int dp[13][5001];
int sum[13][5001];
int f(int pos,int mask){
    if (pos==m+1) return 0;
    if (dp[pos][mask]!=-1) return dp[pos][mask];
    int maxx=f(pos+1,mask);
    for (int j=mask;j;j=((j-1)&mask)){
        maxx=max(maxx,sum[pos][j]+f(pos+1,(mask^j)));
    }
    return dp[pos][mask]=maxx;
}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            v.push_back({a[i][j],j});
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    set<int>st;
    for (auto cur:v){
        if (st.find(cur.second)==st.end()) {
            st.insert(cur.second);
            if (st.size()==n) break;
        }
    }
    int cnt=0;
    for (auto i:st) x[++cnt]=i;
    m=cnt;
    for (int i=0;i<=12;i++) for (int j=0;j<=(1<<12);j++) dp[i][j]=-1;
    for (int pos=1;pos<=m;pos++){
        for (int mask=0;mask<(1<<n);mask++){
             int maxx=0;
             for (int i=0;i<n;i++){
                int cursum=0;
                for (int t=1;t<=n;t++){
                    int cur=t+i;
                    if (cur>n) cur-=n;
                    if (mask&(1<<(cur-1))) cursum+=a[t][x[pos]];
                }
                maxx=max(maxx,cursum);;
             }
             sum[pos][mask]=maxx;
        }

    }
    cout<<f(1,(1<<n)-1)<<endl;

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