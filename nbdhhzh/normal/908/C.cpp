#include<bits/stdc++.h> 
using namespace std;
int n,r,i,a[100010],j;
double b[100010];
int main(){
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=r;
		for(j=1;j<i;j++)
		if(abs(a[i]-a[j])<=2*r)
			b[i]=max(b[i],b[j]+sqrt(4*r*r-(a[i]-a[j])*(a[i]-a[j])));
		printf("%.10lf ",b[i]);
	}
	puts("");
}