#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll ans;
vector<pair<ll,ll> > p,np;
vector<ll> ord,lin;
int main(){
	ll t,i,j,k,x,y;
	scanf("%lld",&t);
	while(t--)
	{
		p.clear();
		ord.clear();
		for(i=0;i<4;i++)
		{
			scanf("%lld%lld",&x,&y);
			ord.push_back(i);
			p.push_back(make_pair(x,y));
		}
		ans=LINF;
		//0->left up; 1->right up; 2->left down; 3->right down
		do
		{
			//can be proven, that if we choose the upper left corner as (x0,y1), it is one of the optimal solutions
			for(k=0;k<4;k++)
			{
				for(j=0;j<4;j++)
				{
					x=p[ord[k]].F;
					y=p[ord[j]].S;
					np.clear();
					for(i=0;i<p.size();i++)
					{
						np.push_back(make_pair(p[ord[i]].F-x,p[ord[i]].S-y));//construct a new grid if we consider (x,y) as (0,0)
					}
					//ans=abs(x1)+abs(y1)+abs(x2-L)+abs(y2)+abs(x3)+abs(-y3-L)+abs(x4-L)+abs(-y4-L)
					lin.clear();
					lin.push_back(np[1].F);
					lin.push_back(-np[2].S);
					lin.push_back(np[3].F);
					lin.push_back(-np[3].S);
					sort(lin.begin(),lin.end());
					//say we have x2,-y3,x4,-y4 sorted as a,b,c,d, then min{abs(x2-L)+abs(-y3-L)+abs(x4-L)+abs(-y4-L)}=c+d-a-b if we choose L in [b,c]
					ans=min(ans,abs(np[0].F)+abs(np[0].S)+abs(np[1].S)+abs(np[2].F)+lin[3]+lin[2]-lin[1]-lin[0]);
				}
			}
		}while(next_permutation(ord.begin(),ord.end()));
		printf("%lld\n",ans);
	}
	return 0;
}