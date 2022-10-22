//AFO countdown:19 Days
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=5e3+10;
int t[M][M],n;
string s;

void work(vector<int>v)
{
	if (v.size()<3)return;
	vector<int>v1,v2;
	for (int i=1;i<v.size();i++)
		if (t[v[0]][v[i]])v2.pb(v[i]);
		else v1.pb(v[i]);
	for (int i=0;i<v2.size();i++)
		for (int j=0;j<v1.size();j++)
			if (t[v2[i]][v1[j]]){cout<<v[0]<<' '<<v2[i]<<' '<<v1[j];exit(0);}
	work(v1),work(v2);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=0;j<n;j++)
			t[i][j+1]=s[j]-'0';
	}vector<int>v;
	for (int i=1;i<=n;i++)v.pb(i);
	work(v);puts("-1");
	return 0;
}