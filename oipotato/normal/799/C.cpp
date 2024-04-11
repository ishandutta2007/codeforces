#include<bits/stdc++.h>
using namespace std;
const int INF=20000000;
int c[2][100010],b[100010],p[100010],n,C,D,ans;
char ch;
int lowbit(int x){return x&(-x);}
void modify(int ord,int x,int y){for(;x<=100000;x+=lowbit(x))c[ord][x]=max(c[ord][x],y);}
int query(int ord,int x){if(x<=0)return 0;int s=0;for(;x;x-=lowbit(x))s=max(s,c[ord][x]);return s;}
int main()
{
	scanf("%d%d%d",&n,&C,&D);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d %c",&b[i],&p[i],&ch);
		if(ch=='C'&&p[i]<=C)
		{
			int tans=max(query(0,C-p[i]),query(1,D));
			if(tans>0)ans=max(ans,tans+b[i]);
			modify(0,p[i],b[i]);
		}
		else if(ch=='D'&&p[i]<=D)
		{
			int tans=max(query(0,C),query(1,D-p[i]));
			if(tans>0)ans=max(ans,tans+b[i]);
			modify(1,p[i],b[i]);
		}
	}
	printf("%d",ans);
	return 0;
}