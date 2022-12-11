#include<bits/stdc++.h>
using namespace std;
char s[100010];
int a[3],t,flag,n,i,p;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		t=(t+s[i])%3,a[s[i]%3]++;
	if(!t){puts(s+1);return 0;}
	for(p=2;s[p]=='0';p++);p-=2;
	if(a[t]&&n>1&&(p<=1||a[t]>1||s[1]%3!=t))a[t]--;else
	if(a[3-t]>1&&n>2)a[3-t]-=2;else
	if(a[t]&&n>1)a[t]--;else
	{puts("-1");return 0;}
	for(i=1;i<=n;i++){
		if(s[i]=='0'&&!flag)continue;
		if(a[s[i]%3])putchar(s[i]),a[s[i]%3]--,flag=1;
	}
	if(!flag)puts("0");
}