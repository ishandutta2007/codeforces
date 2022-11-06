#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=100000;
int n,a,r,m,mc,L=0,R=1000000000;
int h[Maxn+5];
int solve(int x){
	int s1=0,s2=0,pre=0;
	for(int i=1;i<=n;i++){
		if(h[i]>x){
			s1+=h[i]-x;
		}
		if(h[i]<x){
			s2+=x-h[i];
		}
	}
	if(s1>=s2){
		pre=mc*s2+r*(s1-s2);
	}
	else{
		pre=mc*s1+a*(s2-s1);
	}
	return pre;
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&a,&r,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&h[i]);
	}
	mc=min(a+r,m);
	int ans=-1;
	while(L<=R){
		int mid1=L+(R-L)/3,mid2=R-(R-L)/3;
		if(solve(mid1)<solve(mid2)){
			ans=solve(mid1);
			R=mid2-1;
		}
		else{
			ans=solve(mid2);
			L=mid1+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}