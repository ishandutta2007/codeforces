#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=105;
string str[maxn],res[maxn],res2[maxn];
int n,m,cnt;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>str[i];
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)res2[j]=res[j]+str[j][i];
		bool ok=true;
		for(int j=2;j<=n&&ok;j++)if(res2[j]<res2[j-1])ok&=false;
		if(ok)
			for(int j=1;j<=n;j++)res[j]=res2[j];
		else
			cnt++;
	}
	cout<<cnt;
	return 0;
}