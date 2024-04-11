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
using namespace std;
ll k,ans[5][5];
ll getback(ll x)
{
	ll i,ret=0;
	for(i=0;i<18;i++)
	{
		if(x&(1<<i))
		{
			ret+=0;
		}
		else
		{
			ret+=(1<<i);
		}
	}
	return ret;
}
int main(){
	ll i,j;
	cin>>k;
	cout<<3<<" "<<3<<endl; 
	ans[0][0]=(1<<18)-1;
	ans[0][2]=0;
	ans[1][1]=(1<<18)-1;
	ans[2][0]=0;
	ans[2][1]=0;
	ans[2][2]=(1<<18)-1;
	ans[1][0]=k;
	ans[1][2]=k;
	ans[0][1]=getback(k);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}