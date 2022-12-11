#include<bits/stdc++.h>
using namespace std;
int n,q,i;
long long x,m,y,z;
char s[100010];
long long lowbit(long long x){return x&-x;}
int main(){
	scanf("%I64d%d",&m,&q);
	while(q--){
		scanf("%I64d\n%s",&x,s+1);
		n=strlen(s+1);
		for(i=1;i<=n;i++)
		if(s[i]=='U'){
			y=x+lowbit(x);
			z=x-lowbit(x);
			if((lowbit(y)>>1)==lowbit(x)&&y<=m)x=y;
			else if((lowbit(z)>>1)==lowbit(x))x=z;
		}else if(s[i]=='L')x-=lowbit(x)>>1;
		else x+=lowbit(x)>>1;
		printf("%I64d\n",x);
	}
}