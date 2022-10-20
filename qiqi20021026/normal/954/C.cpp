#include<bits/stdc++.h>

using namespace std;

int n,tmp,a[300000];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	tmp=-1;
	for (int i=2;i<=n;++i){
		int x=abs(a[i]-a[i-1]);
		if (!x){puts("NO"); return 0;}
		if (x!=1){
			if (tmp!=-1&&x!=tmp){puts("NO"); return 0;}
			tmp=x;
		}
	}
	if (tmp==-1){
		puts("YES"); printf("%d %d\n",(int)1e9,(int)1e9);
		return 0;
	}
	for (int i=2;i<=n;++i){
		int x=abs(a[i]-a[i-1]);
		if (x==1){
			int k1=a[i],k2=a[i-1];
			if (k1>k2) swap(k1,k2);
			if (k1%tmp==0&&k2%tmp==1){puts("NO"); return 0;}
		}
	}
	puts("YES");
	printf("%d %d\n",(int)1e9,tmp);
	
	return 0;
}