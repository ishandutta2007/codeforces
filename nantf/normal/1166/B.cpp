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
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,sq,x,y;
int main(){
	n=read();
	for(int i=2;i*i<=n;i++) if(n%i==0) x=i,y=n/i;
	if(x<5 || y<5) return puts("-1"),0;
	FOR(i,1,x){
		if(i%5==1){
			printf("aeiou");
			FOR(j,1,y-5) printf("a");
		}
		if(i%5==2){
			printf("eioua");
			FOR(j,1,y-5) printf("e");
		}
		if(i%5==3){
			printf("iouae");
			FOR(j,1,y-5) printf("i");
		}
		if(i%5==4){
			printf("ouaei");
			FOR(j,1,y-5) printf("o");
		}
		if(i%5==0){
			printf("uaeio");
			FOR(j,1,y-5) printf("u");
		}
	}
}