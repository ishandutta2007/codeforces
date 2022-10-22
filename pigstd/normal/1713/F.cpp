#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

int n;
vector<int>f(vector<int>v,int lim)
{
	for (int i=0;(1<<i)<lim;i++)
		for (int j=0;j<lim;j++)
			if ((j>>i)&1)v[j]^=v[j^(1<<i)];
	for (int i=n;i<lim;i++)v[i]=0;
//	for (int i=0;i<lim;i++)cerr<<v[i]<<(i+1==lim?'\n':' ');
	return v;
}

vector<int>g(vector<int>v,int lim)
{
	vector<int>res(lim);
	for (int i=0;i<lim;i++)res[i^(lim-1)]=v[i];
	for (int i=0;(1<<i)<lim;i++)
		for (int j=0;j<lim;j++)
			if ((j>>i)&1)res[j]^=res[j^(1<<i)];
	for (int i=0;i<lim;i++)v[i^(lim-1)]=res[i];
	for (int i=n;i<lim;i++)v[i]=0;
//	for (int i=0;i<lim;i++)cerr<<v[i]<<(i+1==lim?'\n':' ');
	return v;
}

signed main()
{
	n=read();int lim=1;
	while(lim<n)lim<<=1;
	vector<int>v(lim);
	for (int i=0;i<n;i++)v[i]=read();
	auto res=g(f(v,lim),lim);
	for (int i=n-1;i>=0;i--)cout<<res[i]<<(i==0?'\n':' ');
	return 0;
}