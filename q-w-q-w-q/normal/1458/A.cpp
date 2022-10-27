#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll a[200001],b[200001],qwq;
inline ll gcd(ll x,ll y){
	while(x%y){
		ll tp=y;
		y=x%y;
		x=tp;
	}
	return y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=m;i++) scanf("%lld",b+i);
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	if(n==1){
		for(int i=1;i<=m;i++) printf("%lld ",a[1]+b[i]);
		return 0;
	}
	qwq=abs(a[1]-a[2]);
	for(int i=2;i<n;i++) qwq=gcd(qwq,a[i+1]-a[i]);
	for(int i=1;i<=m;i++) printf("%lld ",gcd(qwq,a[1]+b[i]));
}