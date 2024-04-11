#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 300010
#define mod
using namespace std;
int n,m,a[M],p[M],l[M],r[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),l[i]=i-1,r[i]=i+1;
	r[0]=1,l[n+1]=n;
	printf("1");
	for(int i=1;i<=n;i++){
		m=a[i];
		l[r[m]]=l[m];
		r[l[m]]=r[m];
		printf(" %d",i-(n-l[n+1])+1);
	}
	return 0;
}