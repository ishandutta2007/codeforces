#include <cstdio>
#include <vector>

using namespace std;

int n,m;
vector<int> e[100010];

bool vis[100010];
int dep [100010];

bool oce;

int cnt[2];

void dfs(int pos){
    vis[pos]=true;
    int i,sz=e[pos].size(),nxt;
    ++cnt[dep[pos]&1];
    for(i=0;i<sz;++i){
        nxt=e[pos][i];
        if(!vis[nxt]){
            dep[nxt]=dep[pos]+1;
            dfs(nxt);
        } else if((dep[nxt]-dep[pos]+1)&1){
            oce=1;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int i,a,b;
    long long tcnt=0;
    for(i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        e[a].push_back(b); e[b].push_back(a);
    }
    long long asdf=0;
    for(i=1;i<=n;++i) if(!vis[i]) {
        cnt[0]=cnt[1]=0;
        dfs(i);
        asdf+=1LL*cnt[0]*(cnt[0]-1)/2+1LL*cnt[1]*(cnt[1]-1)/2;
    }
    int sz;
    for(i=1;i<=n;++i){
        sz=e[i].size();
        tcnt+=1LL*sz*(sz-1)/2;
    }
    if(oce){
        puts("0 1");
    } else if(tcnt){
        printf("1 %I64d\n",asdf);
    } else if(m){
        printf("2 %I64d\n",1LL*m*(n-2));
    } else {
        printf("3 %I64d\n",1LL*n*(n-1)/2*(n-2)/3);
    }
    return 0;
}