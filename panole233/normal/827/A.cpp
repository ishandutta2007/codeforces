#include<bits/stdc++.h>
using namespace std;

int n,tn,t[1000010],len,Len;
char ans[3000010],s[1000010];

int main()
{
	scanf("%d",&n),Len=0;
	for (int i=1; i<=3000000; i++) ans[i]='a';
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s),len=strlen(s);
		scanf("%d",&tn);
		for (int j=1; j<=tn; j++) scanf("%d",&t[j]);
		t[0]=-100000000,Len=max(Len,len+t[tn]-1);
		for (int j=1; j<=tn; j++)
			for (int nw=max(t[j-1]+len,t[j]),k=nw; k<t[j]+len; k++) ans[k]=s[k-t[j]];
	}
	for (int j=1; j<=Len; j++) putchar(ans[j]); puts("");
	return 0;
}