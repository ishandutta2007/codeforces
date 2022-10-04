#include<bits/stdc++.h>

int n,N,ans,x;
int b[100001];

int main(){
	scanf("%d",&n); N=n;
	while(n--) scanf("%d",&x), b[x]=b[x-1]+1, ans=ans<b[x]?b[x]:ans;
	printf("%d",N-ans);
	return 0;
}