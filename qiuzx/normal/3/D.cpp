#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 50010
using namespace std;
char c[N];
ll n,m=0,l=0,r=0,a[N],b[N],val;
vector<ll> p;
priority_queue<pair<ll,ll> > cap;
string s;
ll cost(string t)
{
	ll i,ret=0;
	for(i=0;i<m;i++)
	{
		if(s[p[i]]=='(')
		{
			ret+=a[i];
		}
		else
		{
			ret+=b[i];
		}
	}
	return ret;
}
int main(){
	ll i,j,y;
	scanf("%s",c);
	s=c;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]=='?')
		{
			m++;
			p.push_back(i);
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%I64d %I64d",&a[i],&b[i]);
		/*cap.push(make_pair(b[i]-a[i],i));
		s[p[i]]=')';*/
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			val++;
		}
		else if(s[i]==')')
		{
			val--;
		}
		else
		{
			val--;
			s[i]=')';
			cap.push(make_pair(b[j]-a[j],i));
			j++;
		}
		if(val<0)
		{
			if(!cap.empty())
			{ 
				y=cap.top().S;
				cap.pop();
				val+=2;
				s[y]='(';
			}
			else
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	if(val==0)
	{
		printf("%I64d\n%s\n",cost(s),s.c_str());
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}