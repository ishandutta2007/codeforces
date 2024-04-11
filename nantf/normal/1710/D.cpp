#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=998244353;
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
int n,al,tmp[maxn],tl,sum[maxn][maxn];
PII ans[maxn];
set<PII> s;
char str[maxn][maxn];
inline void add(int u,int v){
	if(u>v) swap(u,v);
	ans[++al]=MP(u,v);
}
void clear(){
	al=tl=0;
	FOR(i,1,n) tmp[i]=0,ans[i]=MP(0,0);
	FOR(i,1,n) FOR(j,1,n) sum[i][j]=0;
	s.clear();
}
void solve(){
	n=read();
	FOR(i,1,n) scanf("%s",str[i]+1);
	FOR(i,1,n) s.insert(MP(i,i));
	FOR(len,2,n) FOR(l,1,n-len+1){
		int r=l+len-1;
		if(str[l][len]=='0') continue;
		// last se>=l is the one before first fi>l
		// last fi<=r
		auto lft=s.lower_bound(MP(l+1,0)),rig=s.lower_bound(MP(r+1,0));
		lft--;rig--;
//		printf("l=%d,r=%d\n",l,r);
		if(lft==rig) continue;
//		puts("in");
		tmp[tl=1]=l;
		for(auto it=lft;it!=rig;it++){
			if(it==lft) continue;
			tmp[++tl]=it->fi;
		}
		tmp[++tl]=r;
//		FOR(i,1,tl) printf("%d ",tmp[i]);
//		puts("");
		assert(tl!=3);
		if(tl>=4){
			if(tl%2==1){
				int lst=tmp[4];
				FOR(i,1,tl) if(i%2==1) add(lst,tmp[i]),lst=tmp[i];
				FOR(i,2,tl) if(i!=4 && i%2==0) add(lst,tmp[i]),lst=tmp[i];
			}
			else{
				int lst=tmp[2];
				FOR(i,4,tl) if(i%2==0) add(lst,tmp[i]),lst=tmp[i];
				FOR(i,1,tl) if(i%2==1) add(lst,tmp[i]),lst=tmp[i];
			}
		}
		else add(l,r);
		int x=lft->fi,y=rig->se;
		rig++;
		s.erase(lft,rig);
		s.insert(MP(x,y));
	}
	assert(al==n-1);
	FOR(i,1,n-1) printf("%d %d\n",ans[i].fi,ans[i].se),sum[ans[i].fi][ans[i].se]++;
	FOR(i,1,n) FOR(j,1,n) sum[i][j]+=sum[i][j-1];
	ROF(i,n,1) FOR(j,1,n) sum[i][j]+=sum[i+1][j];
	FOR(i,1,n){
		FOR(j,i,n){
			assert((sum[i][j]==j-i)==(str[i][j-i+1]=='1'));
			if((sum[i][j]==j-i)!=(str[i][j-i+1]=='1')) printf("at %d %d\n",i,j);
		}
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}