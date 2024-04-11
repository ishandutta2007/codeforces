#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string,int> m;
string name[1010],winner;
int score[1010],ans,n;
bool ok[1010];
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>name[i]>>score[i];
		m[name[i]]+=score[i];
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,m[name[i]]);
	for(int i=1;i<=n;i++)
		if(m[name[i]]==ans)
			ok[i]=1;
	for(int i=1;i<=n;i++)
		m[name[i]]=0;
	for(int i=1;i<=n;i++)
	{
		m[name[i]]+=score[i];
		if(ok[i]&&m[name[i]]>=ans)
		{
			cout<<name[i]<<endl;
			return 0;
		}
	}
	return 0;
}