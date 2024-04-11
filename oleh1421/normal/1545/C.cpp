//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=1010;
int a[N][N];
int cnt[N][N];
vector<int>g[N][N];
int del[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            g[i][j].clear();
            cnt[i][j]=0;
        }
    }
    for (int i=1;i<=n*2;i++){
        del[i]=0;
        for (int j=1;j<=n;j++) cin>>a[i][j],cnt[j][a[i][j]]++,g[j][a[i][j]].push_back(i);
    }
    set<pair<int,pair<int,int> > >st;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            st.insert({cnt[i][j],{i,j}});
        }
    }
    vector<int>ans;
    ll res=1ll;
    int Cnt=0;
    while (!st.empty()){
        int pos=(*st.begin()).second.first;
        int val=(*st.begin()).second.second;
        if (cnt[pos][val]>1) res=(res*2ll)%mod;
        int ind=-1;
        for (int x:g[pos][val]){
            if (!del[x]){
                ind=x;
                break;
            }
        }
        del[ind]=1;
        for (int i=1;i<=n;i++){
            for (int j:g[i][a[ind][i]]){
                if (!del[j]){
                    del[j]=2;
                    for (int t=1;t<=n;t++){
                        st.erase({cnt[t][a[j][t]],{t,a[j][t]}});
                        cnt[t][a[j][t]]--;
                        st.insert({cnt[t][a[j][t]],{t,a[j][t]}});
                    }
                }
            }
        }
        for (int i=1;i<=n;i++) st.erase({cnt[i][a[ind][i]],{i,a[ind][i]}});
    }

    cout<<res<<endl;
    for (int i=1;i<=n*2;i++){
        if (del[i]==1) cout<<i<<" ";
    }
    cout<<endl;



}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//1001000100010
/**
5
4 5 1 2 3
3 5 2 4 1
1 2 3 4 5
5 2 4 1 3
3 4 5 1 2
2 3 4 5 1
1 3 5 2 4
4 1 3 5 2
2 4 1 3 5
5 1 2 3 4
**/
//100000100010
//1000001000