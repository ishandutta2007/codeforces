#include<bits/stdc++.h>
using namespace std;
char st1[300010],st2[300010],ans[300010];
int n,t1,t2,l,r,n1,n2;
bool cmp(char a,char b){return a>b;}
int main()
{
	scanf("%s",st1);
	scanf("%s",st2);
	n=strlen(st1);
	sort(st1,st1+n);
	sort(st2,st2+n,cmp);
	n1=n/2+n%2-1;
	n2=n/2-1;
	for(t1=t2=0,l=1,r=n;l<=r;)
	{
		if(st1[t1]<st2[t2])ans[l++]=st1[t1++];
		else break;
		if(l>r)break;
		if(st2[t2]>st1[t1])ans[l++]=st2[t2++];
		else
		{
			ans[r--]=st2[n2--];
			break;
		}
	}
	for(;l<=r;)
	{
		ans[r--]=st1[n1--];
		if(r<l)break;
		ans[r--]=st2[n2--];
	}
	for(int i=1;i<=n;i++)printf("%c",ans[i]);
	return 0;
}