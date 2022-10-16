#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
int n;
double p;
inline int c2(int x){return x*(x-1)/2;}
inline int c3(int x){return x*(x-1)*(x-2)/6;}
int main(){
	scanf("%d%lf",&n,&p);
	FOR(i,0,n){
		int j=n-i;
		int all=c3(n),w=c3(i),x=c2(i)*j,y=i*c2(j),z=c3(j);
		if(w+x+y*0.5>=all*p){printf("%d\n",i);break;}
	}
}