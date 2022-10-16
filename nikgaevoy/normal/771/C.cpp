#include<iostream>
#include<math.h>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
long long n, k,i, j, cur,  x[200005], y[200005], vn[200005][5], used[200005], c1, vp[200005], razm[200005], k1, k2;
long long ans1, ans2, s1, s2, s3, ans;
vector<int> v[200005];
void dfs( long long v1)
{
	long long ui, uj, ck, ui1;
	used[v1]=2;
	cur++;
	uj=0;
	for(ui=0; ui<v[v1].size(); ui++)
	{
		if(used[v[v1][ui]]==0)
		{
			uj++;
			dfs(v[v1][ui]);
		}
	}
	if(uj==0)
	{
		razm[v1]=1;
	}
	else
	{
		ck=0;
		for(ui=0; ui<v[v1].size(); ui++)
	    {
		    if(used[v[v1][ui]]==1)
		    {
				ck=ck+razm[v[v1][ui]];
		    }
	    }
		razm[v1]=ck+1;
	}
	//cout<<v1<<' '<<razm[v1]<<endl;
	if(uj==0)
	{
		for(ui=0; ui<k; ui++)
		{
			vn[v1][ui]=0;
		}
		vn[v1][0]=1;
	}
	else
	{
		ck=0;
		for(ui=0; ui<v[v1].size(); ui++)
	    {
		    if(used[v[v1][ui]]==1)
		    {
				for(ui1=0; ui1<k; ui1++)
				{
					vn[v1][(ui1+1)%k]=vn[v1][(ui1+1)%k]+vn[v[v1][ui]][ui1];
				}
		    }
	    }
		vn[v1][0]++;
	}
	used[v1]=1;

}
int main()
{
	cin>>n>>k;
	for(i=1; i<n; i++)
	{
		cin>>x[i]>>y[i];
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	cur=0;
	dfs(1);
	for(i=1; i<n; i++)
	{
		c1=min(razm[x[i]], razm[y[i]]);
		ans1=ans1+long long(c1)*(long long(n-c1));
	}
	for(i=1; i<=n; i++)
	{
		for(j=0; j<k; j++)
		{
		//	cout<<i<<' '<<j<<' '<<vn[i][j]<<endl;
		}
	}
	for(i=1; i<=n; i++)
	{
		for(k1=0; k1<k; k1++)
		{
			for(k2=0; k2<=k1; k2++)
			{
				if(k1!=k2)
				{
					s1=0;
					s2=0; 
					s3=0;
					for(j=0; j<v[i].size(); j++)
					{
						if(razm[v[i][j]]<razm[i])
						{
							s1=s1+vn[v[i][j]][k1];
							s2=s2+vn[v[i][j]][k2];
							s3=s3+vn[v[i][j]][k1]*vn[v[i][j]][k2];
						}
					}
					//cout<<i<<' '<<k1<<' '<<k2<<' '<<(s1*s2-s3)<<endl;
					ans2=ans2+(s1*s2-s3)*((k-(k1+k2+2)%k)%k);
				}
				if(k1==k2)
				{
					s1=0;
					s2=0; 
					s3=0;
					for(j=0; j<v[i].size(); j++)
					{
						if(razm[v[i][j]]<razm[i])
						{
							s1=s1+vn[v[i][j]][k1];
							s3=s3+vn[v[i][j]][k1]*vn[v[i][j]][k1];
						}
					}
					ans2=ans2+((s1*s1-s3)/2)*((k-(k1+k2+2)%k)%k);
					//cout<<i<<' '<<k1<<' '<<k2<<' '<<(s1*s1-s3)/2<<endl;
				}
			}
		}
	}
	for(i=1; i<=n; i++)
	{
		for(k1=0; k1<k; k1++)
		{
			ans2=ans2+vn[i][k1]*((k-k1)%k);
		}
	}
	ans=(ans1+ans2)/k;
	cout<<ans;
	
}