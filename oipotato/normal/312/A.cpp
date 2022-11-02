#include<bits/stdc++.h>
using namespace std;
int n,tot;
bool bo1,bo2;
char st[110],ch;
int main()
{
	scanf("%d",&n);
	gets(st);
	for(int i=1;i<=n;i++)
	{
		bo1=bo2=0;
		gets(st+1);
		tot=strlen(st+1);
		if(tot>=5&&st[1]=='m'&&st[2]=='i'&&st[3]=='a'&&st[4]=='o'&&st[5]=='.')bo1=1;
		if(tot>=5&&st[tot]=='.'&&st[tot-1]=='a'&&st[tot-2]=='l'&&st[tot-3]=='a'&&st[tot-4]=='l')bo2=1;
		if((bo1&&bo2)||(!bo1&&!bo2))printf("OMG>.< I don't know!\n");
		else if(bo1)printf("Rainbow's\n");
		else printf("Freda's\n");
	}
	return 0;
}