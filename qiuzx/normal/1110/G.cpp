#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 2000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
char buf[N];
ll n,deg[N],mxdeg;
vector<ll> vt[N];
bool check(ll x)
{
	ll a=vt[x][0],b=vt[x][1],c=vt[x][2],num=0;
	if(deg[a]>1)
	{
		num++;
	}
	if(deg[b]>1)
	{
		num++;
	}
	if(deg[c]>1)
	{
		num++;
	}
	if(num>=2)
	{
		return true;
	}
	return false;
}
int main(){
	ll T,i,j,cnt,x,y,num;
	T=rint();
	while(T--)
	{
		n=rint();
		for(i=0;i<n*4;i++)
		{
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			x=rint()-1;
			y=rint()-1;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		cnt=n;
		scanf("%s",&buf);
		for(x=0;x<n;x++)
		{
			if(buf[x]=='W')
			{
				vt[x].push_back(cnt);
				vt[cnt].push_back(x);
				vt[cnt].push_back(cnt+1);
				vt[cnt+1].push_back(cnt);
				vt[cnt].push_back(cnt+2);
				vt[cnt+2].push_back(cnt);
				cnt+=3;
			}
		}
		mxdeg=0;
		for(i=0;i<cnt;i++)
		{
			deg[i]=vt[i].size();
			mxdeg=max(mxdeg,deg[i]);
		}
		if(mxdeg>=4)
		{
			puts("White");
			continue;
		}
		num=0;
		for(i=0;i<cnt;i++)
		{
			if(deg[i]==3)
			{
				num++;
				if(check(i))
				{
					i=-1;
					break;
				}
			}
		}
		if(i==-1)
		{
			puts("White");
			continue;
		}
		if(num==0||num==1||cnt%2==0)
		{
			puts("Draw");
		}
		else
		{
			puts("White");
		}
	}
	return 0;
}