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
#define SQ 340
using namespace std;
string s;
ll n,sum[SQ][6];
vector<pair<ll,ll> > qu;
vector<ll> op;
multiset<ll> st[SQ];
ll query()
{
	ll ret=0,i,pos=2;
	for(i=0;i<SQ;i++)
	{
		ret+=sum[i][pos];
		pos=(pos-(st[i].size()%5)+100)%5;
	}
	return ret;
}
void update(ll pos,ll val)
{
	ll i=0,qnum;
	qnum=pos/SQ;
	st[qnum].insert(val);
	memset(sum[qnum],0,sizeof(sum[qnum]));
	for(multiset<ll>::iterator it=st[qnum].begin();it!=st[qnum].end();it++,i++)
	{
		sum[qnum][i%5]+=(*it);
	}
	return;
}
void recall(ll pos,ll val)
{
	ll i=0,qnum;
	qnum=pos/SQ;
	st[qnum].erase(val);
	memset(sum[qnum],0,sizeof(sum[qnum]));
	for(multiset<ll>::iterator it=st[qnum].begin();it!=st[qnum].end();it++,i++)
	{
		sum[qnum][i%5]+=(*it);
	}
	return;
}
int main(){
	ll i,x;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(s=="sum")
		{
			qu.push_back(make_pair(2,0));
			continue;
		}
		scanf("%I64d",&x);
		op.push_back(x);
		if(s=="add")
		{
			qu.push_back(make_pair(0,x));
		}
		else
		{
			qu.push_back(make_pair(1,x));
		}
	}
	sort(op.begin(),op.end());
	op.erase(unique(op.begin(),op.end()),op.end());
	for(i=0;i<qu.size();i++)
	{
		if(qu[i].F==2)
		{
			printf("%I64d\n",query());
		}
		else if(qu[i].F==0)
		{
			update(lower_bound(op.begin(),op.end(),qu[i].S)-op.begin(),qu[i].S);
		}
		else
		{
			recall(lower_bound(op.begin(),op.end(),qu[i].S)-op.begin(),qu[i].S);
		}
	}
	return 0;
}