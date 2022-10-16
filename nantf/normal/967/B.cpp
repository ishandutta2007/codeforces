#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b,s[100010];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",s+i);
		sum+=s[i];
	}
	sort(s+2,s+n+1);
	for(int i=n;i>=1;i--){
		if(a*s[1]/sum>=b){
			printf("%d\n",n-i);
			return 0;
		}
		sum-=s[i];
	}
}