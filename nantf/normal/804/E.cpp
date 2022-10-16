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
int n;
inline void work(int x,int y){
	printf("%d %d\n",x,y);
}
inline void work2(int a,int b,int c,int d){
	work(a,c);
	work(b,d);
	work(a,d);
	work(b,c); 
}
int main(){
	n=read();
	if(n%4>=2) return puts("NO"),0;
	puts("YES");
	FOR(i,0,n/4-1){
		work(i*4+1,i*4+3);
		work(i*4+2,i*4+4);
		work(i*4+1,i*4+4);
		work(i*4+2,i*4+3);
		if(n%4==1) work(i*4+1,n);
		work(i*4+1,i*4+2);
		if(n%4==1) work(i*4+2,n);
		if(n%4==1) work(i*4+3,n);
		work(i*4+3,i*4+4);
		if(n%4==1) work(i*4+4,n);
	}
	FOR(i,0,n/4-1) FOR(j,i+1,n/4-1){
		work2(i*4+1,i*4+2,j*4+1,j*4+2);
		work2(i*4+1,i*4+2,j*4+3,j*4+4);
		work2(i*4+3,i*4+4,j*4+1,j*4+2);
		work2(i*4+3,i*4+4,j*4+3,j*4+4);
	}
} // asdfasdfasdf