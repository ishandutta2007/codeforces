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
#define N 200010
#define B 1800
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
int n,q;
ll r[N],c[N],rd[N],lsttm[N],lst[N],lv[N],ans=0;
bool mrk[N];
vector<pair<ll,pair<ll,ll> > > func[120];
void prework(int id,int L,int R)
{
	pair<ll,ll> cur=make_pair(0,0);
	vector<pair<pair<ll,ll>,ll> > allnd;
	for(int i=L;i<=R;++i)
	{
		cur.F+=r[i];
		allnd.push_back(make_pair(make_pair(rd[i]+1,i),0));
		allnd.push_back(make_pair(make_pair(rd[i]+2,i),1));
	}
	sort(allnd.begin(),allnd.end());
	func[id].push_back(make_pair(0,cur));
	for(int i=0;i<allnd.size();)
	{
		ll pret=allnd[i].F.F;
		while(i<allnd.size()&&allnd[i].F.F==pret)
		{
			ll x=allnd[i].F.S;
			if(allnd[i].S==0)
			{
				cur.F-=r[x];
				cur.F+=c[x]%r[x];
				cur.S+=c[x]-(c[x]%r[x])*(rd[x]+1);
			}
			else
			{
				cur.F-=c[x]%r[x];
				cur.S+=(c[x]%r[x])*(rd[x]+1);
			}
			++i;
		}
		func[id].push_back(make_pair(pret,cur));
	}
	return;
}
ll calc(int id,ll t)
{
	t-=lsttm[id];
	int lo=0,hi=func[id].size(),mid;
	while(lo+1<hi)
	{
		mid=(lo+hi)>>1;
		if(func[id][mid].F>t)
		{
			hi=mid;
		}
		else
		{
			lo=mid;
		}
	}
	return func[id][lo].S.F*t+func[id][lo].S.S;
}
int main(){
	n=rint();
	for(int i=0;i<n;++i)
	{
		lst[i]=-INF,lv[i]=0;
		c[i]=rint(),r[i]=rint();
		rd[i]=c[i]/r[i];
	}
	for(int i=0;i*B<n;++i)
	{
		lsttm[i]=-INF;
		prework(i,i*B,min(n,(i+1)*B)-1);
	}
	q=rint();
	while(q--)
	{
		ll t=rint(),h=rint();
		for(int i=0;i*B<n;++i)
		{
			if(!mrk[i])
			{
				ll v=calc(i,t);
				if(h>=v)
				{
					h-=v;
					lsttm[i]=t;
				}
				else
				{
					mrk[i]=true;
					int L=i*B,R=min(n,(i+1)*B)-1;
					for(int j=L;j<=R;++j)
					{
						lst[j]=lsttm[i];
					}
					for(int j=L;j<=R;++j)
					{
						ll cv=min((t-lst[j])*r[j]+lv[j],c[j]);
						if(h>=cv)
						{
							h-=cv;
							lst[j]=t;
							lv[j]=0;
						}
						else
						{
							lst[j]=t;
							lv[j]=cv-h;
							h=0;
							break;
						}
					}
					break;
				}
			}
			else
			{
				int L=i*B,R=min(n,(i+1)*B)-1;
				for(int j=L;j<=R;++j)
				{
					ll cv=min((t-lst[j])*r[j]+lv[j],c[j]);
					if(h>=cv)
					{
						h-=cv;
						lst[j]=t;
						lv[j]=0;
					}
					else
					{
						lst[j]=t;
						lv[j]=cv-h;
						h=0;
						break;
					}
				}
				if(h==0)
				{
					break;
				}
				lsttm[i]=t;
				mrk[i]=false;
			}
		}
		ans+=h;
	}
	printf("%lld\n",ans);
	return 0;
}