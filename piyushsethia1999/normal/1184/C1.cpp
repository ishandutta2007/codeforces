#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define inf 1500000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long

/////////////

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n;
	cin>>n;
	n=4*n+1;
	pair<int,int> p[n];
	for(int i=0;i<n;++i)
	{
		cin>>p[i].F>>p[i].S;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				for(int l=0;l<n;++l)
				{
					int lx=p[i].F;
					int ly=p[j].S;
					int rx=p[k].F;
					int ry=p[l].S;
					if(rx-lx!=ry-ly)
						continue;
					if(rx<=lx||ry<=ly)
						continue;
					// cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<"\n";
					vector<pair<int,int>> v;
					for(int e=0;e<n;++e)
					{
						if((lx==p[e].F||rx==p[e].F)&&ly<=p[e].S&&ry>=p[e].S)
							continue;
						if((ly==p[e].S||ry==p[e].S)&&lx<=p[e].F&&rx>=p[e].F)
							continue;
						v.push_back(p[e]);
					}
					if(v.size()==1)
					{
						cout<<v[0].F<<" "<<v[0].S;
						return 0;
					}
				}
			}
		}
	}
}