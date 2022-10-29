#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
// typedef pair<int,int> pii;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
// head

const int N=5;
int T,n,k;
int sum[N],way[N][N],cnt[N],deg[N];

int fa[N],tot[N],mi[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void uni(int x,int y,int z) {
	x=find(x),y=find(y);
	if (x!=y) {
		fa[x]=y;
		tot[y]+=tot[x];
	}
	tot[y]+=z;
}

bool bridge(int a,int b) {return cnt[a]==1||cnt[b]==1;}

int main() {
	memset(way,inf,sizeof(way));
	scanf("%d",&n);
	rep(i,1,5) fa[i]=i;
	rep(i,1,n+1) {
		int x,y,v;
		scanf("%d%d%d",&x,&v,&y);
		uni(x,y,v);
		if (x==y) sum[x]+=v;
		else way[x][y]=way[y][x]=min(way[x][y],v),cnt[x]++,cnt[y]++;
		deg[x]++,deg[y]++;
	}
	int ans=0;
	rep(i,1,5) {
		int rot=find(i),ct=0;
		rep(j,1,5) if (find(j)==rot&&(deg[j]&1)) ct++;
		if (ct<=2) ans=max(ans,tot[rot]);
		else {
			rep(j,1,5) rep(k,j+1,5) if (way[j][k]!=inf) {
				if (bridge(j,k)) {
					int sol=cnt[j]==1?j:k;
					ans=max(ans,sum[sol]);
					ans=max(ans,tot[rot]-sum[sol]-way[j][k]);
				}else {
					ans=max(ans,tot[rot]-way[j][k]);	
				}
			}
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}