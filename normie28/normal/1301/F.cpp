
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
using namespace std;
 
typedef pair<int,int> P;
vector<P> v[45];
int dis[45][1000005],vis[45];
int a[1005][1005];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int inf=0x3f3f3f3f;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int p=1;p<=k;p++) dis[p][(i-1)*m+j]=inf;
            cin>>a[i][j];
            v[a[i][j]].push_back(P(i,j));
        }
    }
    for(int i=1;i<=k;i++){
        queue<P> q;
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        for(auto j:v[i]) dis[i][(j.first-1)*m+j.second]=0,q.push(j);
        while(!q.empty()){
            P temp=q.front();
            int u=(temp.first-1)*m+temp.second;
            q.pop();
            if(!vis[a[temp.first][temp.second]]){
                vis[a[temp.first][temp.second]]=1;
                for(auto p:v[a[temp.first][temp.second]]){
                    if(dis[i][u]+1<dis[i][(p.first-1)*m+p.second])
                        dis[i][(p.first-1)*m+p.second]=dis[i][u]+1,
                        q.push(p);
                }
            }
            for(int j=0;j<4;j++){
                int x=temp.first+dir[j][0],y=temp.second+dir[j][1];
                if(x<1 || x>n || y<1 || y>m) continue;
                int vv=(x-1)*m+y;
                if(dis[i][vv]>dis[i][u]+1){
                    q.push(P(x,y));
                    dis[i][vv]=dis[i][u]+1;
                }
            }
        }
    }
    int qq;
    cin>>qq;
    for(int i=0;i<qq;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int res=abs(x2-x1)+abs(y2-y1);
        for(int j=1;j<=k;j++){
            res=min(res,dis[j][(x1-1)*m+y1]+dis[j][(x2-1)*m+y2]+1);
        }
        cout<<res<<'\n';
    }
}