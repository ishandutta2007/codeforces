#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
#define mod
using namespace std;
int n,m,ans[200],num,t;
int main(){
	scanf("%d",&n);
	for(int i=max(1,n-150);i<n;i++){
		m=t=i;
		while(m>0){
			t+=m%10;
			m/=10;
		}
		if(t==n) ans[++num]=i;
	}
	printf("%d",num);
	for(int i=1;i<=num;i++) printf("\n%d",ans[i]);
	return 0;
}