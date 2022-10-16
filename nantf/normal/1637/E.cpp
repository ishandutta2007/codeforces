#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,a[maxn],tmp[maxn],tl,seq[maxn],sl,cnt[maxn];
map<PII,bool> vis;
vector<int> v[maxn];
void clear(){
	vis.clear();
	FOR(i,0,n) v[i].clear(),cnt[i]=0;
	tl=sl=0;
}
void solve(){
	n=read();m=read();
	FOR(i,1,n) tmp[++tl]=a[i]=read();
	sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(i,1,n) a[i]=lower_bound(tmp+1,tmp+tl+1,a[i])-tmp;
	FOR(i,1,m){
		int x=read(),y=read();
		x=lower_bound(tmp+1,tmp+tl+1,x)-tmp;
		y=lower_bound(tmp+1,tmp+tl+1,y)-tmp;
		vis[MP(x,y)]=vis[MP(y,x)]=true;
	}
	FOR(i,1,n) cnt[a[i]]++;
	ROF(i,n,1) if(cnt[i]) v[cnt[i]].PB(i);
	ll ans=0;
	FOR(i,1,n) if(!v[i].empty()) seq[++sl]=i;
	FOR(ii,1,sl){
		int i=seq[ii];
//		printf("i=%d\n",i);
		FOR(j,0,(int)v[i].size()-1){
			int x=v[i][j];
			FOR(k,j+1,(int)v[i].size()-1){
				int y=v[i][k];
				if(vis[MP(x,y)]) continue;
				else{ans=max(ans,2ll*i*(tmp[x]+tmp[y]));break;}
			}
		}
		FOR(jj,1,ii-1){
			int j=seq[jj];
//			printf("j=%d\n",j);
			FOR(k,0,(int)v[i].size()-1){
				int x=v[i][k];
//				printf("x=%d\n",x);
				FOR(l,0,(int)v[j].size()-1){
					int y=v[j][l];
//					printf("y=%d\n",y);
					if(vis[MP(x,y)]) continue;
					else{ans=max(ans,1ll*(i+j)*(tmp[x]+tmp[y]));break;}
				}
			}
		}
	}
	printf("%lld\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}