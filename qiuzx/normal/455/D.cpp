#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
#define M 350
using namespace std;
int n,q,sq,lastans=0,num[M][N];
deque<int> dq[M];
int change(int x)
{
	return ((x+lastans-1+n*100)%n+1);
}
int main(){
	int i,j,tp,x,y,z,l,r;
	cin>>n;
	sq=(int)sqrt(n);
	memset(num,0,sizeof(num));
	for(i=0;i<n;i++)
	{
		cin>>x;
		dq[i/sq].push_back(x);
		num[i/sq][x]++;
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>tp>>x>>y;
		x=change(x);
		y=change(y);
		x--;
		y--;
		if(x>y)
		{
			swap(x,y);
		}
		l=x/sq;
		r=y/sq;
		//cout<<x<<" "<<y<<" ";
		if(tp==2)
		{
			cin>>z;
			z=change(z);
			//cout<<z<<endl;
			lastans=0;
			if(l==r)
			{
				for(j=x%sq;j<=y%sq;j++)
				{
					if(dq[l][j]==z)
					{
						lastans++;
					}
				}
			}
			else
			{
				for(j=l+1;j<r;j++)
				{
					lastans+=num[j][z];
				}
				for(j=x%sq;j<sq;j++)
				{
					if(dq[l][j]==z)
					{
						lastans++;
					}
				}
				for(j=0;j<=y%sq;j++)
				{
					if(dq[r][j]==z)
					{
						lastans++;
					}
				}
			}
			cout<<lastans<<endl;
		}
		else
		{
			//cout<<endl;
			if(l==r)
			{
				z=dq[l][y%sq];
				dq[l].erase(dq[l].begin()+(y%sq));
				dq[l].insert(dq[l].begin()+(x%sq),z);
			}
			else
			{
				z=dq[r][y%sq];
				dq[r].erase(dq[r].begin()+(y%sq));
				num[r][z]--;
				dq[l].insert(dq[l].begin()+(x%sq),z);
   				num[l][z]++;
				for(j=l;j<=r;j++)
				{
					if(j>l)
					{
						dq[j].push_front(z);
						num[j][z]++;
					}
					z=dq[j].back();
					//cout<<z<<endl;
					if(j<r)
					{
						dq[j].pop_back();
						num[j][z]--;
					}
				}
			}
		}
	}
	return 0;
}