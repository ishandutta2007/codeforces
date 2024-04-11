#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
int n,a[300],tot;
int check(int x){
	int tmp=x;
	while (tmp){
		x+=tmp%10;
		tmp/=10;
	}
	return x;
}
int main() {
	scanf("%d",&n);
	for (int i=max(1,n-200);i<n;i++)
	if (check(i)==n) a[tot++]=i;
	printf("%d\n",tot);
	for (int i=0;i<tot;i++) printf("%d\n",a[i]);
}