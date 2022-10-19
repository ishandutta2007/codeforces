#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 110 
using namespace std;
ll u,v,hmn[N],fs[N],ans=0,up=0;
bool solve(ll bit)
{
	ll i,x,y,ndu;
	x=(u&((ll)1<<bit))!=0;//1 
	y=(v&((ll)1<<bit))!=0;//
	ndu=((((u&((ll)1<<(bit+1)))!=0)!=((v&((ll)1<<(bit+1)))!=0)));//
	if((y+200-up)%2!=x)// 
	{
		return false;
	}
	if(!x)// 
	{
		if(up==0)
		{
			if(ndu==0)
			{
				hmn[bit]=0;
			}
			else
			{
				hmn[bit]=2;
				up=1;
			}
		}
		else if(up==1)
		{
			if(ndu==0)
			{
				hmn[bit]=0;
				up=0;
			}
			else
			{
				hmn[bit]=2;
			}
		}
		else
		{
			if(ndu==0)
			{
				hmn[bit]=2;
			}
			else
			{
				hmn[bit]=0;
				up=1;
			}
		}
	}
	else// 
	{
		if(up==0)
		{
			if(ndu==0)
			{
				hmn[bit]=1;
			}
			else
			{
				hmn[bit]=3;
				up=1;
			}
		}
		else if(up==1)
		{
			if(ndu==0)
			{
				hmn[bit]=3;
				up=2;
			}
			else
			{
				hmn[bit]=1;
			}
		}
		else
		{
			if(ndu==0)
			{
				hmn[bit]=3;
			}
			else
			{
				hmn[bit]=1;
				up=1;
			}
		}
	}
	return true;
}
void printans()
{
	ll i,j;
	for(i=0;i<61;i++)
	{
		for(j=0;j<hmn[i];j++)//1 
		{
			fs[j]+=((ll)1<<i);
		}
	}
	for(i=0;i<ans;i++)
	{
		cout<<fs[i]<<" ";
	}
	cout<<endl;
	return;
}
int main(){
	ll i;
	cin>>u>>v;
	memset(hmn,0,sizeof(hmn));
	for(i=0;i<61;i++)// 
	{
		if(!solve(i))
		{
			cout<<-1<<endl;
			return 0;
		}
		ans=max(ans,hmn[i]);
	}
	if(up!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
	memset(fs,0,sizeof(fs));
	printans();
	return 0;
}