#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666;
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
int n,q,a[maxn],h,r,mxa,cyc,xx[maxn],yy[maxn];
int main(){
	h=1;
	r=n=read();q=read();
	FOR(i,1,n) a[i]=read(),mxa=max(mxa,a[i]);
	while(true){
		int x=a[h],y=a[h+1];
		xx[++cyc]=x;yy[cyc]=y;
		if(x<y) swap(x,y);
		a[++h]=x;a[++r]=y;
		if(a[h]==mxa) break;
	}
	while(q--){
		ll x=read();
		if(x<=cyc) printf("%d %d\n",xx[x],yy[x]);
		else printf("%d %d\n",mxa,a[(x-cyc-1)%(n-1)+h+1]);
	}
}