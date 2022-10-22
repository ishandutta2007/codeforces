#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int a,b,c,m;

vector<int>x,y,z;

ll ans1,ans2;

int main()
{
	cin>>a>>b>>c;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int v;
		char ty[5];
		cin>>v;
		scanf("%s",ty);
		if(ty[0]=='U')
			x.push_back(v);
		else
			y.push_back(v);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=0;i<min((int)x.size(),a);i++)
		ans2+=x[i];
	for(int i=0;i<min((int)y.size(),b);i++)
		ans2+=y[i];
	ans1=min((int)x.size(),a)+min((int)y.size(),b);
	for(int i=a;i<(int)x.size();i++)
		z.push_back(x[i]);
	for(int i=b;i<(int)y.size();i++)
		z.push_back(y[i]);
	sort(z.begin(),z.end());
	for(int i=0;i<min((int)z.size(),c);i++)
		ans2+=z[i];
	ans1+=min((int)z.size(),c);
	cout<<ans1<<" "<<ans2;
}