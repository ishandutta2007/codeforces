#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define Luogu judging
int n;
char s[200010];
int a[200010];
int Ans;

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	F(i,1,n) s[n+i]=s[i];
	a[1]=1;
	F(i,2,n*2) if(s[i]==s[i-1]) a[i]=1; else a[i]=a[i-1]+1;
	F(i,1,n*2) Ans=max(Ans,min(n,a[i]));
	printf("%d",Ans);
	return 0;
}