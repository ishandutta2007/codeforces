#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
char c[3];
long long a,ans=INF,num;
vector<long long> np;
void dfs(long long step,vector<long long> ch)
{
	int i,j;
	if(step>=3)
	{
		ans=min(ans,ch[0]);
		return;
	}
	for(i=0;i<ch.size();i++)
	{
		for(j=i+1;j<ch.size();j++)
		{
			np=ch;
			if(c[step]=='*')
			{
				np.push_back(np[i]*np[j]);
			}
			else
			{
				np.push_back(np[i]+np[j]);
			}
			np.erase(np.begin()+i);
			np.erase(np.begin()+j-1);
			dfs(step+1,np);
		}
	}
}
int main(){
	int i;
	for(i=0;i<4;i++)
	{
		cin>>a;
		np.push_back(a);
	}
	for(i=0;i<3;i++)
	{
		cin>>c[i];
	}
	dfs((long long)0,np);
	cout<<ans<<endl;
	return 0;
}