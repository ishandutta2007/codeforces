#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,cnt,pt[maxn];
inline int rnd(){
	static int seed=2333;
	return seed=(((seed*666666ll+20050818)%998244353)^1000000007)%1004535809;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	n=read();
	if(n<=60){
		int mx=0,mn=INT_MAX;
		FOR(i,1,n){
			printf("? %d\n",i);
			fflush(stdout);
			int x=read();
			mx=max(mx,x);
			mn=min(mn,x);
		}
		printf("! %d %d\n",mn,(mx-mn)/(n-1));
		fflush(stdout);
		return 0;
	}
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		printf("> %d\n",mid);
		cnt++;
		fflush(stdout);
		int ver=read();
		if(ver) l=mid+1;
		else r=mid;
	}
	int mx=r,ans=0;
	FOR(i,1,n) pt[i]=i;
	FOR(i,1,n) swap(pt[i],pt[rnd()%n+1]);
	FOR(i,1,min(n,60-cnt)){
		printf("? %d\n",pt[i]);
		fflush(stdout);
		int x=read();
		ans=gcd(ans,mx-x);
	}
	printf("! %d %d\n",mx-(n-1)*ans,ans);
	fflush(stdout);
}
//CDWDDW