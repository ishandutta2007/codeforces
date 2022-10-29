#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
// head

const int N=4e5+5;
int T,n,m;

bool vis[N];

int fa[N],cnt[N];
void init(int n) {
    rep(i,1,2*n+1) fa[i]=i,cnt[i]=0,vis[i]=0;   
}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int u,int v) {
    fa[find(u)]=find(v);
}

int main() {
    cin>>T;
    while (T--) {
        scanf("%d%d",&n,&m);
        init(n);
        
        rep(i,1,m+1) {
            int u,v;
            char s[10];
            scanf("%d%d%s",&u,&v,s);
            if (s[0]=='c') {
                unite(u,v);
                unite(u+n,v+n);
            }else {
                unite(u,v+n);
                unite(u+n,v);
            }
        }
        
        bool ok=1;
        rep(i,1,n+1) if (find(i)==find(i+n)) {ok=0; break;}
        if (!ok) {puts("-1"); continue;}
        
        rep(i,n+1,2*n+1) cnt[find(i)]++;
        
        int ans=0;
        rep(i,1,n+1) {
            if (vis[find(i)]||vis[find(i+n)]) continue;
            int c1=cnt[find(i)],c2=cnt[find(i+n)];
            ans+=max(c1,c2);
            vis[find(i)]=vis[find(i+n)]=1;
        }
        
        printf("%d\n",ans);
    }

    return 0;
}