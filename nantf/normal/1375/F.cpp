#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
ll a,b,c;
int main(){
	a=read();b=read();c=read();
	puts("First");
	ll x=3*max(max(a,b),c)-a-b-c;
	printf("%lld\n",x);
	fflush(stdout);
	int id=read();
	if(id==1){
		if(a<b || a<c){
			printf("%lld\n",max(b,c)-min(b,c));
			fflush(stdout);
			return 0;
		} 
		a+=x;
	}
	if(id==2){
		if(b<a || b<c){
			printf("%lld\n",max(a,c)-min(a,c));
			fflush(stdout);
			return 0;
		} 
		b+=x;
	}
	if(id==3){
		if(c<a || c<b){
			printf("%lld\n",max(a,b)-min(a,b));
			fflush(stdout);
			return 0;
		} 
		c+=x;
	}
	x=3*max(max(a,b),c)-a-b-c;
	printf("%lld\n",x);
	fflush(stdout);
	id=read();
	if(id==1){
		if(a<b || a<c){
			printf("%lld\n",max(b,c)-min(b,c));
			fflush(stdout);
			return 0;
		} 
		a+=x;
	}
	if(id==2){
		if(b<a || b<c){
			printf("%lld\n",max(a,c)-min(a,c));
			fflush(stdout);
			return 0;
		} 
		b+=x;
	}
	if(id==3){
		if(c<a || c<b){
			printf("%lld\n",max(a,b)-min(a,b));
			fflush(stdout);
			return 0;
		} 
		c+=x;
	}
}