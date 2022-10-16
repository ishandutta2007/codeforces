#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=200020;
int m,a[maxn],b[maxn],up[maxn],down[maxn],cnt[202][202];
int gcd(int x,int y){
	if(x<y) swap(x,y);
	if(x%y==0) return y;
	return gcd(y,x%y);
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("\n(%d+%d)/%d",&a[i],&b[i],&down[i]);
		up[i]=a[i]+b[i];
		int g=gcd(up[i],down[i]);
		up[i]/=g;down[i]/=g;
		cnt[up[i]][down[i]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[up[i]][down[i]]);
	printf("\n");
}