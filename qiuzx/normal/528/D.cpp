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
#define N 200010
using namespace std;
string s,t;
ll k,dif[4][N],val[4];
bitset<N> pos[4],ans;
int main(){
	ll x,y,i,j;
	cin>>x>>y>>k>>s>>t;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='A')
		{
			dif[0][max((ll)0,i-k)]++;
			dif[0][min(i+k+1,(ll)s.size())]--;
		}
		else if(s[i]=='G')
		{
			dif[1][max((ll)0,i-k)]++;
			dif[1][min(i+k+1,(ll)s.size())]--;
		}
		else if(s[i]=='C')
		{
			dif[2][max((ll)0,i-k)]++;
			dif[2][min(i+k+1,(ll)s.size())]--;
		}
		else
		{
			dif[3][max((ll)0,i-k)]++;
			dif[3][min(i+k+1,(ll)s.size())]--;
		}
	}
	for(i=0;i<s.size();i++)
	{
		for(j=0;j<4;j++)
		{
			val[j]+=dif[j][i];
			if(val[j]>0)
			{
				pos[j][i]=true;
			}
		}
	}
	for(i=0;i<s.size();i++)
	{
		ans[i]=true;
	}
	for(i=0;i<t.size();i++)
	{
		if(t[i]=='A')
		{
			ans&=(pos[0]>>i);
		}
		else if(t[i]=='G')
		{
			ans&=(pos[1]>>i);
		}
		else if(t[i]=='C')
		{
			ans&=(pos[2]>>i);
		}
		else
		{
			ans&=(pos[3]>>i);
		}
	}
	cout<<ans.count()<<endl;
	return 0;
}