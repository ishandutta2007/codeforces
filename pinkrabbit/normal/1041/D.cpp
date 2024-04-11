#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define LL long long
int n; LL h;
LL l[300001],r[300001];
LL sum[300001],len[300001];
LL Ans;
int main(){
	scanf("%d%lld",&n,&h);
	F(i,1,n) scanf("%lld%lld",l+i,r+i);
	l[n+1]=3e9;
	dF(i,n,1) sum[i]=sum[i+1]+(l[i+1]-r[i]);
	F(i,1,n) len[i]=r[i]-l[i];
	int j=n;
	LL S=0;
	dF(i,n,1){
		S+=len[i];
		while(sum[i]-sum[j]>=h) S-=len[j], --j;
		Ans=max(Ans,S+h);
	}
	printf("%lld",Ans);
	return 0;
}