#include <bits/stdc++.h>
using namespace std;
string s,ans,tem,tem2;
char c[1000010];
int n;
int main(){
	int i,j,pos;
	scanf("%d%s",&n,c);
	ans=c;
	printf("%s",ans.c_str());
	for(i=1;i<n;i++)
	{
		scanf("%s",c);
		s=c;
		pos=min(min((int)s.size(),(int)ans.size()),4);
		for(j=min(s.size(),ans.size());j>0;j--)
		{
			if(ans.substr(ans.size()-min(j,pos))!=s.substr(j-min(j,pos),min(j,pos)))
			{
				continue;
			}
			if(ans.substr(ans.size()-j)==s.substr(0,j))
			{
				break;
			}
		}
		s=s.substr(j);
		ans+=s;
		printf("%s",s.c_str());
	}
	return 0;
}