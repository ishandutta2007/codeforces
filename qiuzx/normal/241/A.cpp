#include <bits/stdc++.h>
#define N 1010
using namespace std;
int main(){
	int m,k,i,d[N],s[N],hour=0,tank=0,add=0;
	cin>>m>>k;
	for(i=0;i<m;i++)
	{
		cin>>d[i];
		hour+=d[i];
	}
	for(i=0;i<m;i++)
		cin>>s[i];
	for(i=0;i<m;i++)
	{
		add=max(add,s[i]);
		tank+=s[i];
		while(tank<d[i])
		{
			hour+=k;
			tank+=add;
		}
		tank-=d[i];
	}
	cout<<hour<<endl;
	return 0;
}