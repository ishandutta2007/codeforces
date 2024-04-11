#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int t,n,m,x,k[N],c[N],v;
vector<int>a[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
	    v=0;
		for(int i=1;i<=n;i++)
			c[i]=0;
		for(int i=1;i<=m;i++)
		{
			cin>>k[i],a[i].clear();
			while(k[i]--&&cin>>x)
				a[i].push_back(x);
			if(a[i].size()==1)
				c[x]++;
		}
		for(int i=1;i<=n;i++)
    		if(c[i]>(m+1)/2)
    		    v=1;
        if(v)
    	{
    		cout<<"NO"<<'\n';
    		continue;
    	}
		cout<<"YES"<<'\n';
		for(int i=1;i<=m;i++)
			if(a[i].size()==1)
				cout<<a[i][0]<<' ';
			else if(c[a[i][0]]<c[a[i][1]])
				cout<<a[i][0]<<' ',c[a[i][0]]++;
			else
				cout<<a[i][1]<<' ',c[a[i][1]]++;
		cout<<'\n';
	}
	return 0;
}