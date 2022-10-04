#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
// from_luogu
int n; LL Ans;
int l[300001],r[300001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",l+i,r+i);
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	F(i,1,n) Ans+=max(l[i],r[i]);
	printf("%lld",Ans+n);
	return 0;
}