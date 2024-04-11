#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=1000000007;
#define MP make_pair
#define PB push_back
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
struct dat{
	int x,y;
	dat(int xx=0,int yy=0):x(xx),y(yy){}
	dat operator+(const dat &d)const{
		dat ans;
		ans.x=(x+d.x)%mod;
		ans.y=(y+d.y)%mod;
		return ans;
	}
	dat operator+=(const dat &d){
		return *this=*this+d;
	}
	dat operator-(const dat &d)const{
		dat ans;
		ans.x=(x-d.x+mod)%mod;
		ans.y=(y-d.y+mod)%mod;
		return ans;
	}
	dat operator-=(const dat &d){
		return *this=*this-d;
	}
	dat operator*(const dat &d)const{
		dat ans;
		ans.x=1ll*x*d.x%mod;
		ans.y=(1ll*x*d.y+1ll*y*d.x)%mod;
		return ans;
	}
	dat operator*=(const dat &d){
		return *this=*this*d;
	}
}b[maxn],f[maxn],g[maxn];
int n,a[maxn],tmp[maxn],tl,lst[maxn],r[maxn];
vector<int> vec[maxn];
inline void update(int p,dat v){
	for(int i=p;i<=n;i+=i&-i) b[i]+=v;
}
inline dat query(int p){
	dat s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
inline void undo(int p){
	for(int i=p;i<=n;i+=i&-i) b[i]=dat();
}
void clear(){
	FOR(i,0,n) vec[i].clear();
	FOR(i,1,n) a[i]=tmp[i]=lst[i]=r[i]=0;
	tl=0; 
}
void solve(){
	n=read();
	FOR(i,1,n) tmp[++tl]=a[i]=read();
	sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(i,1,n) a[i]=lower_bound(tmp+1,tmp+tl+1,a[i])-tmp;
	dat ans;
	FOR(i,1,n){
		f[i]=dat(1,1)+query(a[i]-1)*dat(1,1);
		update(a[i],f[i]);
		ans+=f[i];
	}
	FOR(i,1,n) undo(a[i]);
	FOR(i,1,n) lst[a[i]]=i;
	ROF(i,n,1) lst[i]=max(lst[i],lst[i+1]);
	FOR(i,1,n){
		r[i]=lst[a[i]+1];
		if(r[i]>i) vec[r[i]].PB(i);
	}
	FOR(i,1,n) if(r[i]<i){
//		printf("i=%d\n",i);
		ROF(j,(int)vec[i].size()-1,0){
			int k=vec[i][j],x=f[k].x;
			g[k]=query(n+1-a[k]-1)+dat(1,1);
			update(n+1-a[k],g[k]);
			g[k]*=f[k];
//			printf("g[%d]=%d\n",k,g[k].x);
			ans-=dat(g[k].x,g[k].x);
		}
		ans-=dat(f[i].x,f[i].x);
		FOR(j,0,(int)vec[i].size()-1){
			int k=vec[i][j];
			undo(n+1-a[k]);
		}
	}
	printf("%d\n",ans.y);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}