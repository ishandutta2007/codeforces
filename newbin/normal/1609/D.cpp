#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
int fa[maxn];
int fnd(int x){ return x == fa[x]?x:fa[x] = fnd(fa[x]);}
int sz[maxn];
int link(int x, int y){
    x = fnd(x), y = fnd(y);
    if(x == y) return 0;
    sz[x] += sz[y]+1;
    fa[y] = x; return 1;
}
int a[maxn], b[maxn];
int n, d;
int sol(int p){
    fors(i,1,n+1) fa[i] = i, sz[i] = 0;
    int res = 0;
    fors(i,1,p+1){
        if(!link(a[i],b[i])) res++;
    }
    vector<int> t;
    fors(i,1,n+1) if(fa[i] == i) t.pb(sz[i]);
    sort(all(t)); reverse(all(t));
    int ans = t[0];
    for(int i = 1; i <= res; ++i) ans += t[i]+1;
    return ans;
}
int main(){
    cin>>n>>d;
    fors(i,1,d+1) scanf("%d%d", &a[i], &b[i]);
    fors(i,1,d+1){
        printf("%d\n", sol(i));
    }
    return 0;
}