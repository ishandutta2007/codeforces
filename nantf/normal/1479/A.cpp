#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n;
inline int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
inline void report(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main(){
	n=read();
	int l=1,r=n;
	while(r-l>=2){
		int mid=(l+r)>>1;
		int x=query(mid-1),y=query(mid),z=query(mid+1);
		if(y<x && y<z) report(mid);
		if(x<y) r=mid-1;
		else if(z<y) l=mid+1;
	}
	if(l==r) report(l);
	else report(query(l)<query(r)?l:r);
}