#include <bits/stdc++.h>
#define maxn 300300
typedef long long ll;
using namespace std;

int pai[maxn];
int sz[maxn];

int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    pai[b] = a;
    sz[a] += sz[b];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        pai[i] = i, sz[i] = 1;
    for(int i=0,a,b;i<m;i++){
        scanf("%d%d",&a,&b), a--, b--;
        merge(a,b);
    }
    ll s = 0;
    for(int i=0;i<n;i++)
        if(find(i) == i)
            s += ((ll)sz[find(i)]*(sz[find(i)]-1))/2;
    printf("%s\n",(s==m)?"YES":"NO");
}