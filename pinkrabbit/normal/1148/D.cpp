#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,k1,k2,k;
int a[MN],b[MN],p[MN],c[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",a+i,b+i),p[i]=i;
	F(i,1,n){
		if(a[i]<b[i])++k1;
		if(a[i]>b[i])++k2;
	}
	int d=k1>k2;
	sort(p+1,p+n+1,d?[](int i,int j){return b[i]>b[j];}:[](int i,int j){return b[i]<b[j];});
	printf("%d\n",d?k1:k2);
	F(I,1,n){
		int i=p[I];
		if(a[i]==b[i])continue;
		if((a[i]>b[i])^d)c[++k]=i;
	}
	F(i,1,k)printf("%d ",c[i]);
	return 0;
}