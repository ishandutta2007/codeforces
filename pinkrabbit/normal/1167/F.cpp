#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 500005
#define ll long long
#define mod 1000000007
int n,m,q,k;
int a[MN],p[MN];
int b1[MN],b2[MN],Ans;
inline void add(int*b,int i,int x){for(;i<=n;i+=i&-i)b[i]=(b[i]+x)%mod;}
inline int qur(int*b,int i){int a=0;for(;i;i-=i&-i)a=(a+b[i])%mod;return a;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]<a[j];});
	F(i,1,n){
		int w=p[i];
		add(b1,w,w);
		Ans=(Ans+a[w]*((ll)(n-w+1)*qur(b1,w)%mod+(ll)w*qur(b2,n-w+1)%mod))%mod;
		add(b2,n-w+1,n-w+1);
	}
	printf("%d\n",Ans);
	return 0;
}