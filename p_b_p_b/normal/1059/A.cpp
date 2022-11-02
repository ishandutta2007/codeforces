#include<bits/stdc++.h>
using namespace std;
int n,l,a,lft[100010],rig[100010],ans;
int main(){
	scanf("%d%d%d",&n,&l,&a);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d%d",lft+i,&x);rig[i]=lft[i]+x;
	}
	lft[n+1]=l;rig[0]=0;
	for(int i=0;i<=n;i++) ans+=(lft[i+1]-rig[i])/a;
	printf("%d\n",ans);
}