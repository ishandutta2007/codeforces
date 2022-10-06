#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n;
int a[MN],p[MN],b[MN];
int a0[MM],a1[MM],t;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i,b[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]==a[j]?i<j:a[i]<a[j];});
	F(i,1,n)a[p[i]]=i;
//	F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
	dF(i,n,1){
		F(j,1,i-1)if(a[j]>a[j+1]){
			++t,a0[t]=b[j],a1[t]=b[j+1];
			swap(a[j],a[j+1]);
			swap(b[j],b[j+1]);
		}
	}
	printf("%d\n",t);
	dF(i,t,1)printf("%d %d\n",a0[i],a1[i]);
	return 0;
}