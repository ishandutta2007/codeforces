#include<bits/stdc++.h>
using namespace std;
int x[1005],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x[i]=a+b+c+d;
	}
	int rk=1;
	for (int i=2;i<=n;i++)
		rk+=x[i]>x[1];
	printf("%d\n",rk);
}