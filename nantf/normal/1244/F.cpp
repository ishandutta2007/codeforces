#include<bits/stdc++.h>
using namespace std;
int n,k,pos,a[222222],b[444444],c[222222];
char s[222222];
bool flag;
int main(){
	scanf("%d%d",&n,&k),cin>>s+1;
	for(int i=1;i<=n;i++)a[i]=s[i]=='B';
	a[0]=a[n],a[n+1]=a[1];
	for(int i=1;i<=n;i++)b[i]=(a[i]==a[i-1]||a[i]==a[i+1]),b[i+n]=b[i];
	for(int i=1;i<=n;i++)if(b[i]){flag=1;break;}
	if(!flag){for(int i=1;i<=n;i++)printf("%c",s[i+k%2]);return 0;}
	for(int i=1;i<=n;i++)if(b[i])pos=i;
	for(int i=n+1;i<=n*2;c[i-n]=i-pos,i++)if(b[i])pos=i;
	for(int i=n*2;i>n;i--)if(b[i])pos=i;
	for(int i=n;i>=1;c[i]=min(c[i],pos-i),i--)if(b[i])pos=i;
	for(int i=1;i<=n;i++)if(!b[i])a[i]^=(min(k,c[i])%2);
	for(int i=1;i<=n;i++)a[i]?printf("B"):printf("W");
}