#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define LL long long

int n,m,xb,a[300],b[300];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	sort(b+1,b+m+1);
	
	int j=0;
	for (int i=n;i>=1;i--)
		if (a[i]==0){
			j++;
			a[i]=b[j];
		}
	
	for (int i=2;i<=n;i++)
		if (a[i]<=a[i-1]){
			puts("Yes");
			return 0;
		}
	
	puts("No");
	
	return 0;
}