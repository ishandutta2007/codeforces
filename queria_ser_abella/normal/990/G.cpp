#include <bits/stdc++.h>
#define ll long long
#define maxn 300300
#define pii pair<int,int>
#define pb push_back
using namespace std;

int lbl[maxn];
int qtd[maxn];

vector<pii> edge[maxn];

ll F[maxn];
ll f[maxn];

int pai[maxn];
int last[maxn];
int sz[maxn];

int ts = 1;

int find(int x){
    if(last[x] != ts){
        last[x] = ts;
        pai[x] = x;
        sz[x] = 1;
    }
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
    
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",lbl+i);
        qtd[lbl[i]]++;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        int g = __gcd(lbl[a],lbl[b]);
        edge[g].pb(pii(a,b));
    }
    
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i)
            F[i] += qtd[j];
        ts++;
        for(int j=i;j<maxn;j+=i){
            for(int k=0;k<(int)edge[j].size();k++){
                int a = edge[j][k].first, b = edge[j][k].second;
                a = find(a);
                b = find(b);
                F[i] += (ll) sz[a] * sz[b];
                sz[a] += sz[b];
                pai[b] = a;
            }
        }
    }
    
    for(int i=maxn-1;i>=1;i--)
        for(int j=2*i;j<maxn;j+=i)
            F[i] -= F[j];
    
    for(int i=1;i<maxn;i++)
        if(F[i])
            printf("%d %lld\n",i,F[i]);
    
}