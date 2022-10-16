#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
const double PI=3.141592653589793;
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
int n,at,id[maxn],a[maxn],cnt,ans[maxn][2],al;
bool vis[maxn];
struct point{
	int x,y,id;
	point operator-(const point &p)const{return (point){x-p.x,y-p.y,id};}
	double ang()const{return atan2(y,x);}
	bool operator<(const point &p)const{
		if(p.id==at) return false;
		if(id==at) return true;
		return ang()<p.ang();
	}
}p[maxn],q[maxn];
inline void add(int x,int y){
	ans[++al][0]=x;
	ans[al][1]=y;
	swap(a[x],a[y]);
}
void dfs(int x){
	id[x]=cnt;
	if(!id[a[x]]) dfs(a[x]);
}
int main(){
	n=read();
	FOR(i,1,n) p[i].x=read(),p[i].y=read(),a[i]=read(),p[i].id=i;
	FOR(i,1,n) if(i!=a[i]){
		if(!at || MP(p[i].x,p[i].y)<MP(p[at].x,p[at].y)) at=i;
	}
	if(!at) return puts("0"),0;
	FOR(i,1,n) if(!id[i]) cnt++,dfs(i);
	FOR(i,1,n) if(i!=at) p[i]=p[i]-p[at];
	sort(p+1,p+n+1);
	if(p[n].ang()-p[2].ang()>PI){
		ROF(i,n,2) if(p[i].ang()-p[2].ang()<PI){
			q[1]=p[1];
			FOR(j,i+1,n) q[j-i+1]=p[j];
			FOR(j,2,i) q[n-i+j]=p[j];
			break;
		}
	}
	else FOR(i,1,n) q[i]=p[i];
	vis[id[q[2].id]]=true;
	FOR(i,3,n) if(!vis[id[q[i].id]]){
		add(q[i].id,q[i-1].id);
		vis[id[q[i].id]]=true;
	}
	while(a[at]!=at) add(a[at],at);
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d\n",ans[i][0],ans[i][1]);
}