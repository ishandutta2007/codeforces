#include <cstdio>

int n,m;

int par[101][101];

int root (int* parent,int x) { return parent[x]<0?x:parent[x]=root(parent,parent[x]); }
void join(int* parent,int a,int b) { if(root(parent,a)!=root(parent,b)) parent[root(parent,a)]=root(parent,b); }

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(j=1;j<=m;++j) for(i=1;i<=n;++i) par[j][i]=-1;
    int a,b,c;
    for(i=0;i<m;++i) scanf("%d%d%d",&a,&b,&c),join(par[c],a,b);
    int q;
    scanf("%d",&q);
    int cnt;
    for(;q--;) {
        cnt=0;
        scanf("%d%d",&a,&b);
        for(i=1;i<=m;++i) if(root(par[i],a)==root(par[i],b)) ++cnt;
        printf("%d\n",cnt);
    }
    return 0;
}