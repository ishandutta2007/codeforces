#include <bits/stdc++.h>
#define N 300010
using namespace std;
int main(){
	long long ans=0,i,j,cur;
	char c[N];
	string s;
	scanf("%s",c);
	s=c;
	for(i=0;i<s.size();i++)
	{
		if((s[i]-'0')%4==0)
		{
			ans++;
		}
		if(!i)
		{
			continue;
		}
		cur=s[i]-'0'+(s[i-1]-'0')*10;
		if(cur%4==0)
		{
			ans+=i;
		}
	}
	//printf("%d\n",ans);
	cout<<ans<<endl;
	return 0;
}