#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
int n,p[maxn],tmp[maxn],id[maxn],cnt,ans[maxn][maxn];
inline bool ask1(int x,int y){
	printf("1 %d %d\n",x-1,y-1);
	fflush(stdout);
	return read();
}
inline bool ask2(int x,vector<int> v){
	printf("2 %d %d ",x-1,(int)v.size());
	FOR(i,0,(int)v.size()-1) printf("%d ",v[i]-1);
	puts("");
	fflush(stdout);
	return read();
}
void clear(){
	FOR(i,1,n) p[i]=tmp[i]=id[i]=0;
	FOR(i,1,n) FOR(j,1,n) ans[i][j]=0;
	cnt=0;
}
void work(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	work(l,mid);
	work(mid+1,r);
	int x=l,y=mid+1,cur=l;
	while(x<=mid && y<=r) tmp[cur++]=ask1(p[x],p[y])?p[x++]:p[y++];
	while(x<=mid) tmp[cur++]=p[x++];
	while(y<=r) tmp[cur++]=p[y++];
	FOR(i,l,r) p[i]=tmp[i];
}
void solve(){
	n=read();
	FOR(i,1,n) p[i]=i;
	work(1,n);
	id[n]=cnt=1;
	int cur=n;
	ROF(i,n,1){
		if(i<cur) id[cur=i]=++cnt;
		if(cur==1) break;
		vector<int> v;
		FOR(j,1,cur-1) v.PB(p[j]);
		if(ask2(p[i],v)){
			id[--cur]=id[i];
			i++;
		}
	}
	FOR(i,1,n) FOR(j,1,n) ans[p[i]][p[j]]=i<=j || id[i]==id[j];
	puts("3");
	FOR(i,1,n){
		FOR(j,1,n) printf("%d",ans[i][j]);
		puts("");
	}
	fflush(stdout);
	clear();
	if(read()==-1) exit(0);
}
int main(){
	int T=read();
	while(T--) solve();
}