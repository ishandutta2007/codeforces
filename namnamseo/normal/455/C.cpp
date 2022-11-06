#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
void read(int& a){ scanf("%d",&a); }
void read(double& a){ scanf("%lf",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int n,m,q;

// disj
int par[300010];
int R(int x){ return (x==par[x])?x:(par[x]=R(par[x])); }

// max
int mxl[300010];

vector<int> edge[300010];

bool vis[300010];
int furt[300010];
typedef pair<int,int> pp;

bool unvis;

pp dfs(int x){
    vis[x]=!unvis;
    pp ret(0,x);
    for(auto& nxt:edge[x]){
        if(vis[nxt]==unvis){
            pp tmp = dfs(nxt);
            ++tmp.first;
            ret=max(ret,tmp);
        }
    }
    return ret;
}

int main()
{
    read(n,m,q);
    int i;
    for(i=1; i<=n; ++i) par[i]=i;
    for(;m--;){
        int x,y;
        read(x,y);
        edge[x].pb(y);
        edge[y].pb(x);
        par[R(x)]=R(y);
    }
    for(i=1; i<=n; ++i){
        int a=R(i);
        if(vis[a]==unvis){
            furt[a]=dfs(a).second;
        }
    }
    unvis = !unvis;
    for(i=1; i<=n; ++i){
        int a=R(i);
        if(vis[a]==unvis){
            mxl[a]=dfs(furt[a]).first;
            //printf("%d : %d\n",a,mxl[a]);
        }
    }
    for(;q--;){
        int cmd, x;
        read(cmd,x);
        if(cmd==1){
            printf("%d\n",mxl[R(x)]);
        } else {
            int y;
            read(y);
            x=R(x); y=R(y);
            if(x==y) continue;
            //printf("x %d y %d; mxl %d %d\n",x,y,mxl[x],mxl[y]);
            par[x]=y;
            mxl[y] = max(max(mxl[x], mxl[y]), (mxl[x]+1)/2 + (mxl[y]+1)/2 + 1);
        }
    }
    return 0;
}