#include<iostream>
#include<cstdio>
using namespace std;
int n,s,h[101],m[101],t[101];
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d%d",h+i,m+i);
		t[i]=h[i]*60+m[i];
	}
	t[0]=-s-1;
	for(int i=1;i<=n;i++)
		if(t[i]-t[i-1]>=2*(s+1)){
			int sum=t[i-1]+s+1;
			printf("%d %d\n",sum/60,sum%60);
			return 0;
		}
	int sum=t[n]+s+1;
	printf("%d %d\n",sum/60,sum%60);
}