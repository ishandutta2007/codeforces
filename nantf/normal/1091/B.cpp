#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,x[1111],y[1111],a[1111],b[1111];
bool vis[1111];
map<PII,int> id;
int main(){
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read(),id[MP(x[i],y[i])]=i;
	FOR(i,1,n) a[i]=read(),b[i]=read();
	if(n==1) return printf("%d %d\n",a[1]+x[1],b[1]+y[1]),0;
	FOR(i,1,n) FOR(j,1,n){
		if(i==j) continue;
		if(a[1]+x[i]!=a[2]+x[j] || b[1]+y[i]!=b[2]+y[j]) continue;
		bool flag=true;vis[i]=vis[j]=true;
		FOR(k,3,n){
			int d=id[MP(a[1]+x[i]-a[k],b[1]+y[i]-b[k])];
			if(!d || vis[d]){flag=false;break;}
			vis[d]=true;
		}
		vis[i]=vis[j]=false;
		FOR(k,3,n){
			int d=id[MP(a[1]+x[i]-a[k],b[1]+y[i]-b[k])];
			if(d) vis[d]=false;
		}
		if(!flag) continue;
		return printf("%d %d\n",a[1]+x[i],b[1]+y[i]),0;
	}
}