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
#define N 1010
using namespace std;
string s;
int ans=0;
bool book[N];
vector<int> ind[N];
int main(){
	int i,j;
	cin>>s;
	memset(book,false,sizeof(book));
	while(1)
	{
		j=s.size()-1;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='('&&!book[i])
			{
				for(;j>i;j--)
				{
					if(s[j]==')'&&!book[j])
					{
						break;
					}
				}
				if(j<=i)
				{
					break;
				}
				ind[ans].push_back(i+1);
				ind[ans].push_back(j+1);
				book[i]=true;
				book[j]=true;
			}
		}
		if(ind[ans].size()==0)
		{
			break;
		}
		ans++;
	}
	cout<<ans<<endl;
	for(i=0;i<ans;i++)
	{
		sort(ind[i].begin(),ind[i].end());
		cout<<ind[i].size()<<endl;
		for(j=0;j<ind[i].size();j++)
		{
			cout<<ind[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}