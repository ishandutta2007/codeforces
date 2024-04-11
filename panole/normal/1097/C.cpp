#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
int n,len,nw,r;
char s[500011];

struct node{int x,y;}a[100001];
bool cmp(node a,node b) {return a.x<b.x;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s); len=strlen(s);
		a[i].x=a[i].y=0;
		for (int j=0; j<len; j++)
			if (s[j]=='(') a[i].x++;
			else {a[i].x--; if (a[i].y<-a[i].x) a[i].y=-a[i].x;}
		if (a[i].x<=0&&a[i].y>-a[i].x||a[i].x>0&&a[i].y>0) a[i].x=inf;
	}
	sort(a+1,a+1+n,cmp); r=n; nw=0;
	for (int i=1; i<=n; i++)
	{
		while (r>i&&a[r].x>-a[i].x) r--;
		if (r<=i) break;
		if (r<=n&&a[r].x==-a[i].x) nw++,r--;
	}
	printf("%d\n",nw);
	return 0;
}