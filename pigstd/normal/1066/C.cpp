#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

map<int,int>t;
int n,l=1,r=0;

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s;int x;cin>>s>>x;
		if (s=="?")
			cout<<min(t[x]-l,r-t[x])<<endl;
		else if (s=="L")t[x]=--l;
		else t[x]=++r;
	}
	return 0;
}