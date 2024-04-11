#include<bits/stdc++.h>
using namespace std;
int n,k,l,a[100010],ans,f[100010];
long long res;
int main(){
	scanf("%d%d%d",&n,&k,&l);
	for (int i=0;i<n*k;i++) scanf("%d",&a[i]);
	sort(a,a+n*k);
	for (int i=0;i<n*k;i+=k) f[i]=1;
	res=0;
	for (int i=n*k-1;i>=0;i--){
		if (res&&!f[i]&&a[i]<=a[0]+l){
			res--;
			f[i]=1;
		}
		if (f[i]&&a[i]>a[0]+l){
			f[i]=0;
			res++;
		}
	}
	if (res) printf("0\n");
	else{
		for (int i=0;i<n*k;i++) res+=f[i]*a[i];
		printf("%lld\n",res);
	}
}