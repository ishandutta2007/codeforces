#include<bits/stdc++.h>
using namespace std;
int n,m,k,T;
int p[555],c[555];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int fl=1;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i]>>c[i];
			if(p[i]<p[i-1]||c[i]<c[i-1]||(p[i]-p[i-1])<(c[i]-c[i-1]))fl=0;
		}
		cout<<(fl?"YES":"NO")<<endl;
	}
	return 0;
}