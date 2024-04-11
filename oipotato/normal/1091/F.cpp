#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=100010;
int n,cnt,Last;
long long MyANS;
long long pos[N],yzcaa[N],cjbsb[N];
int p[N],fuck[N];
set<pair<int,pair<int,long long>>> MySet;
char jwwok[N];
int cmp(int a,int b){return p[a]<p[b];}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&pos[i]);
	scanf("%s",jwwok+1);
	rep(i,n)
	{ 
		if(jwwok[i]=='W')MySet.insert(make_pair(1,make_pair(i,pos[i]))),Last=1;
		else if(jwwok[i]=='G')MySet.insert(make_pair(0,make_pair(i,pos[i])));
		else
		{
			long long X=pos[i];
			while (X&&MySet.size()!=0)
			{
				auto x=*--MySet.end();
				MySet.erase(--MySet.end());
				MyANS+=(x.first==0?6ll:4ll)*min(x.second.second,X);
				if(x.second.second>X)
				{
					x.second.second-=X;
					MySet.insert(x);
					X=0;
				}
				else X-=x.second.second;
			}
			if(X)
			{	
				if(!Last)MyANS+=6ll*X;
				else MyANS+=4ll*X;
			}
		}
	}
	for(auto i:MySet)
	{
		yzcaa[++cnt]=i.first;
		cjbsb[cnt]=i.second.second;
		p[cnt]=i.second.first;
	}
	rep(i,cnt)fuck[i]=i;
	sort(fuck+1,fuck+cnt+1,cmp); 
	long long C=0;
	for (int i=cnt;i>=1;i--)
	{
		int X=fuck[i];
		if(!yzcaa[X])C+=cjbsb[X];
		else
		{
			if(C<cjbsb[X])
			{
			    MyANS+=4ll*C;
			    cjbsb[X]-=C;
			    C=0;
			    MyANS+=2ll*cjbsb[X];
			}
			else
			{ 
				C-=cjbsb[X];
				MyANS+=4ll*cjbsb[X];
			}
		}	
	}
	printf("%lld\n",MyANS+3ll*C);
	return 0;
}