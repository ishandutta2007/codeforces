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
int lstx=-1,lsty=-1,n,ans;
int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),y=read();
		if(x>=lsty && lstx<lsty) ans++,lstx=lsty;
		if(y>=lstx && lsty<lstx) ans++,lsty=lstx;
		if(lstx==lsty) ans+=min(x-lstx,y-lsty);
		lstx=x;lsty=y;
	}
	printf("%d\n",ans);
}