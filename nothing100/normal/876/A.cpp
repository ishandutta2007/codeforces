#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,a,b,c;
int main() {
	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if (n==1) printf("0\n");
	else if (min(a,b)<c) printf("%d\n",(n-1)*min(a,b));
	else printf("%d\n",min(a,b)+(n-2)*c);
}