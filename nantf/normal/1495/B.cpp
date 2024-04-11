#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define ls o<<1
#define rs o<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
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
inline int qmo(int x){return x+((x>>31)&mod);}
int n,p[maxn],lu[maxn],ld[maxn],ru[maxn],rd[maxn],pre[maxn],suf[maxn];
int main(){
	n=read();
	FOR(i,1,n) p[i]=read();
	lu[1]=ld[1]=1;
	FOR(i,2,n){
		if(p[i]>p[i-1]) ld[i]=ld[i-1]+1,lu[i]=1;
		else lu[i]=lu[i-1]+1,ld[i]=1;
	}
	ru[n]=rd[n]=1;
	ROF(i,n-1,1){
		if(p[i]>p[i+1]) rd[i]=rd[i+1]+1,ru[i]=1;
		else ru[i]=ru[i+1]+1,rd[i]=1;
	}
	FOR(i,1,n) pre[i]=max(pre[i-1],max(lu[i],ru[i]));
	ROF(i,n,1) suf[i]=max(suf[i+1],max(lu[i],ru[i]));
	int ans=0;
	FOR(i,1,n){
		if(ld[i]==1 || rd[i]==1) continue;
		bool flag=true;
//		printf("ld[%d]=%d,rd[%d]=%d\n",i,ld[i],i,rd[i]);
		if(pre[i-ld[i]]>=max(ld[i],rd[i])) flag=false;
		if(suf[i+rd[i]]>=max(ld[i],rd[i])) flag=false;
		FOR(j,i-ld[i]+1,i-1){
			if(lu[j]>=max(ld[i],rd[i])) flag=false;
//			if(j-(i-ld[i]+1)>=max(i-j-1,rd[i]-1)) flag=false,puts("f3");
			if(i-j>=rd[i]-1 && (i-j)%2==1) flag=false;
		}
		FOR(j,i+1,i+rd[i]-1){
			if(ru[j]>=max(ld[i],rd[i])) flag=false;
//			if((i+rd[i]-1)-j>=max(j-i-1,ld[i]-1)) flag=false,puts("f5");
			if(j-i>=ld[i]-1 && (j-i)%2==1) flag=false;
		}
		if(flag) ans++;//,printf("%d ok\n",i);
	}
	printf("%d\n",ans);
}
/*
7
4 3 2 5 7 6 1
*/