#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int n,m;
LL a[300001],b[300001];
set<LL> st;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), a[i]+=a[i-1];
	scanf("%d",&m);
	F(i,1,m) scanf("%d",b+i), b[i]+=b[i-1];
	if(a[n]!=b[m]) return 0*puts("-1");
	F(i,1,n) st.insert(a[i]);
	int Ans=0;
	F(i,1,m) if(st.count(b[i])>=1) ++Ans;
	printf("%d",Ans);
	return 0;
}