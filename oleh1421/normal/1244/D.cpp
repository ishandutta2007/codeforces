#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
///#define int long long
#define endl '\n'
#define int long long
vector<int>v;
int c[300001][3];

vector<int>g[300001];
vector<int>u;
void dfs(int v,int pr){
    u.push_back(v);
    for (auto to:g[v]){
        if (to!=pr) dfs(to,v);
    }
}
int dp[100001][3][3];
int color[300001];
int32_t main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i][0];
    for (int i=1;i<=n;i++) cin>>c[i][1];
    for (int i=1;i<=n;i++) cin>>c[i][2];
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()>=3){
            cout<<-1;
            return 0;
        }
    }
    int root=-1;
    for (int i=1;i<=n;i++){
        if (g[i].size()<=1){
            root=i;
            break;
        }
    }
    dfs(root,0);
    ll res=1000000000000001ll;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (j==i) continue;
            vector<int>v;
            v.push_back(i);
            v.push_back(j);
            ll cur=c[u[0]][i]+c[u[1]][j];
            int last1=i;
            int last2=j;
            for (int t=2;t<n;t++){
                cur+=c[u[t]][3^last1^last2];
                int x=3^last1^last2;
                v.push_back(x);
                last1=last2;
                last2=x;
            }
            if (res>cur){
                res=cur;
                for (int t=0;t<n;t++){
                    color[u[t]]=v[t];
                }
            }
        }
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++) cout<<color[i]+1<<" ";

    /*int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        string s;cin>>s;
        int l=-1;
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                l=i;
                break;
            }
        }
        int r=-1;
        //reverse(s.begin(),s.end());
        for (int i=n-1;i>=0;i--){
            if (s[i]=='1'){
                r=i;
                break;
            }
        }
        if (l==-1) cout<<n<<endl;
        else cout<<max(max({n-l,r})*2,n)<<endl;
    }*/
    return 0;
}
  /*  int n,k;cin>>n>>k;
    set<int>st;
    int minx=100000001;
    int maxx=-1;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
        st.insert(x);
        minx=min(minx,x);
        maxx=max(maxx,x0)
    }
    vector<int>v;
    for (auto i:st) v.push_back(i);*/