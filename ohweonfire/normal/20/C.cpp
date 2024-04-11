#include <stdio.h>
#include <utility>
#include <set>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=100005;
ll res[maxn];
int prev[maxn];
int mark[maxn];
vector<pair<int,int> >g[maxn];
set<pair<ll,int> >all;
void out(int x)
{
 	 if(x!=0)out(prev[x]);
 	 printf("%d ",x+1);
}
int main()
{
 	 int n,m,a,b,c;
 	 scanf("%d%d",&n,&m);
 	 for(int i=0;i<m;i++)
 	 {
	  		   scanf("%d%d%d",&a,&b,&c);
	  		   a--;
	  		   b--;
	  		   g[a].pb(make_pair(b,c));
	  		   g[b].pb(make_pair(a,c));
	 }
	 all.insert(make_pair(0,0));
	 prev[0]=0;
	 mark[0]=1;
	 while(!all.empty())
	 {
	  					 ll d=all.begin()->first;
	  					 int i=all.begin()->second;
	  					 all.erase(all.begin());
	  					 mark[i]=2;
	  					 for(int j=0;j<g[i].size();++j)
	  					 {
						  		 int k=g[i][j].first;
						  		 ll D=d+g[i][j].second;
						  		 if(mark[k]==0||mark[k]==1&&res[k]>D)
						  		 {
								  									 if(mark[k]==1)all.erase(make_pair(res[k],k));
																	  			   mark[k]=1;
																	  			   res[k]=D;
																	  			   prev[k]=i;
																	  			   all.insert(make_pair(D,k));
								}
						}
		}
		if(mark[n-1]==2)out(n-1);else puts("-1");
		return 0;
}