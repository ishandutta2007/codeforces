#include<bits/stdc++.h> 
using namespace std;
int n,i,dad[100010],use[100010];
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d",&dad[i+1]),use[dad[i+1]]=1;
	for(i=n;i>=1;i--)
		if(!use[i])use[dad[i]]++;
	for(i=1;i<=n;i++)
		if(use[i]>0&&use[i]<4)break;
	if(i>n)puts("Yes");else puts("No");
}