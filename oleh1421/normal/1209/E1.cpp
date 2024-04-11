#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
int a[10][10001];
int x[2001];
int n,m;
int r[20001];
int maxx[20001];

int f(int pos,int mask){
    if (pos==m+1) return 0;
    int maxx=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<(1<<n);j++){
            if ((mask&j)==j){
                int sum=0;
                for (int t=1;t<=n;t++){
                    int cur=t+i;
                    if (cur>n) cur-=n;
                    if (j&(1<<(cur-1))) sum+=a[t][x[pos]];
                }
                int x=sum+f(pos+1,mask^j);
                //if (pos==2 && mask==2) cout<<j<<" "<<sum<<endl;
               // if (x==11) cout<<pos<<" "<<mask<<" "<<i<<" "<<j<<" "<<sum<<endl;
              //  if (j==0) cout<<sum<<endl;
                maxx=max(maxx,x);
            }
        }
    }
    return maxx;
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