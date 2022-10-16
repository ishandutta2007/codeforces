#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=1000000007;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
struct vec{
	int len,x[2],id;
	vec(){len=x[0]=x[1]=id=0;}
}a[maxn],b[maxn];
int n,m,tmp[maxn],tl,fa[maxn];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	n=read();m=read();
	FOR(i,1,n){
		a[i].len=read();
		FOR(j,0,a[i].len-1) a[i].x[j]=read();
		sort(a[i].x,a[i].x+a[i].len,greater<int>());
		a[i].id=i;
	}
	FOR(i,1,m) fa[i]=i;
	FOR(i,1,n){
		while(a[i].len){
//			printf("try %d %d %d\n",a[i].len,a[i].x[0],a[i].x[1]);
			int now=a[i].x[0];
			if(!b[now].len){
				b[now]=a[i];
				break;
			}
			a[i].x[0]=a[i].x[1];
			a[i].x[1]=0;
			a[i].len--;
			if(b[now].len==2){
				a[i].len++;
				a[i].x[a[i].len-1]=getfa(b[now].x[1]);
				sort(a[i].x,a[i].x+a[i].len,greater<int>());
				if(a[i].len==2 && a[i].x[0]==a[i].x[1]) a[i]=vec();
			}
		}
		if(a[i].len==2){
			int now=a[i].x[0],to=a[i].x[1];
			fa[getfa(now)]=to;
		}
//		printf("a[i].len=%d,getfa(2)=%d\n",a[i].len,getfa(2));
	}
	FOR(i,1,m) if(b[i].len) tmp[++tl]=b[i].id;
	sort(tmp+1,tmp+tl+1);
	printf("%d %d\n",qpow(2,tl),tl);
	FOR(i,1,tl) printf("%d ",tmp[i]); 
}
/*
3 3
2 2 3
2 1 2
2 3 1
*/