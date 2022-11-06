#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

int par[10010];
int root(int x){ return (x==par[x])?x:(par[x]=root(par[x])); }
void join(int a, int b){
    a=root(a); b=root(b);
    par[a]=b;
}
bool chk[10010];

int main()
{
    int n; read(n);
    for(int i=1; i<=n; ++i){
        par[i]=i;
    }
    for(int i=1; i<=n; ++i){
        int x; read(x);
        join(i, x);
    }
    int ans=0;
    for(int i=1; i<=n; ++i){
        int r=root(i);
        ans+=!chk[r];
        chk[r]=1;
    }
    printf("%d\n", ans);
    return 0;
}