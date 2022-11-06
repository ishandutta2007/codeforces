#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n,m;
void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

vector<vector<int> > table;
vector<vector<int> > ind;

vector<int> edge[1000010];
int value[1000010];

int par[1000010];
int R(int x){ return (par[x]==x)?x:(par[x]=R(par[x])); }
bool join(int a,int b){
    a=R(a); b=R(b);
    if(par[a]!=b){
        //printf("%d = %d\n",a,b);
        par[a]=b;
        return true;
    }
    return false;
}

const int dx[5]={0,1,0,-1,0};

int hist[1000010], hind;
bool dfsvis[1000010];
void dfs(int x){
    dfsvis[x]=true;
    for(int& nxt:edge[x]){
        //printf("%d->%d\n",x,nxt);
        if(!dfsvis[nxt]) dfs(nxt);
    }
    hist[hind++]=x;
}

typedef pair<int,int> pp;
pp asdf[1000010];

int main()
{
    read(n,m);
    int i,j,ii=0;
    table.resize(n);
    ind  .resize(n);
    for(i=0;i<n;++i){
        table[i].resize(m);
        ind  [i].resize(m);
        for(j=0;j<m;++j){
            read(table[i][j]);
            ind[i][j]=ii;
            par[ii]=ii;
            asdf[j]={table[i][j],ii};
            ++ii;
        }
        sort(asdf,asdf+m);
        for(j=1;j<m;++j){
            int& cur=asdf[j].second, &bef=asdf[j-1].second;
            if(asdf[j].first==asdf[j-1].first) join(cur,bef);
        }
    }
    for(j=0;j<m;++j){
        for(i=0;i<n;++i){
            asdf[i]={table[i][j],ind[i][j]};
        }
        sort(asdf,asdf+n);
        for(i=1;i<n;++i){
            int& cur=asdf[i].second, &bef=asdf[i-1].second;
            if(asdf[i].first==asdf[i-1].first) join(cur,bef);
        }
    }
    
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            asdf[j]={table[i][j],ind[i][j]};
        }
        sort(asdf,asdf+m);
        for(j=1;j<m;++j){
            int& cur=asdf[j].second, &bef=asdf[j-1].second;
            if(asdf[j].first!=asdf[j-1].first) edge[R(bef)].push_back(R(cur));
        }
    }
    
    for(j=0;j<m;++j){
        for(i=0;i<n;++i){
            asdf[i]={table[i][j],ind[i][j]};
        }
        sort(asdf,asdf+n);
        for(i=1;i<n;++i){
            int& cur=asdf[i].second, &bef=asdf[i-1].second;
            if(asdf[i].first!=asdf[i-1].first) edge[R(bef)].push_back(R(cur));
        }
    }
    
    for(i=0; i<ii; ++i) if(!dfsvis[R(i)]) dfs(R(i));

    for(i=hind;i--;){
        int me=hist[i];
        for(auto& nxt:edge[me]){
            value[nxt]=max(value[nxt], value[me]+1);
        }
    }

    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            printf("%d ",value[R(ind[i][j])]+1);
        }
        putchar(10);
    }
    return 0;
}