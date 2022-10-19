//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define double long double
#define N 300010
using namespace std;
const double eps=1e-9;
ll n,a,b,p[N],q[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&a,&b);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&q[i]);
		}
		if(a==0&&b==0)
		{
			for(i=0;i<n;i++)
			{
				puts("0.000000000000000");
			}
			continue;
		}
		pair<double,double> mn=make_pair(b,a),mx=make_pair(b,a);
		multiset<pair<double,double> > mst;
		for(i=0;i<n;i++)
		{
			mn.F-=q[i];
			mn.S+=p[i];
			mx.F+=q[i];
			mx.S-=p[i];
			mst.insert(make_pair((double)p[i]/(double)q[i],(double)q[i]*2.0));
			while(!mst.empty())
			{
				if(mn.F>(-eps))
				{
					break;
				}
				multiset<pair<double,double> >::iterator it=mst.begin();
				pair<double,double> cur=*it;
				mst.erase(it);
				double del=min(cur.S,-mn.F);
				mn.F+=del;
				mn.S-=del*cur.F;
				cur.S-=del;
				if(cur.S>eps)
				{
					mst.insert(cur);
				}
			}
			printf("%.15Lf\n",mn.S);
			while(!mst.empty())
			{
				if(mx.S>(-eps))
				{
					break;
				}
				multiset<pair<double,double> >::iterator it=mst.end();
				it--;
				pair<double,double> cur=*it;
				mst.erase(it);
				double del=min(cur.S,-mx.S/cur.F);
				mx.F-=del;
				mx.S+=del*cur.F;
				cur.S-=del;
				if(cur.S>eps)
				{
					mst.insert(cur);
				}
			}
		}
	}
	return 0;
}