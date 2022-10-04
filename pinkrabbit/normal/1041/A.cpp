#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
int n;
int a[300001];
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%d",a[n]-a[1]+1-n);
	return 0;
}