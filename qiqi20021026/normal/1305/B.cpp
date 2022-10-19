#include<bits/stdc++.h>

using namespace std;

#define N 1200

int n,sum,ans[N];
char s[N];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1,j=n;i<j;++i,--j){
		for (;i<=n&&s[i]==')';++i);
		for (;j&&s[j]=='(';--j);
		if (s[i]=='('&&s[j]==')'&&i<j){ans[i]=ans[j]=1; sum+=2;}
	}
	if (!sum){puts("0"); return 0;}
	puts("1");
	printf("%d\n",sum);
	for (int i=1,j=0;i<=n;++i) if (ans[i]) printf(++j==sum?"%d\n":"%d ",i);
	
	return 0;
}