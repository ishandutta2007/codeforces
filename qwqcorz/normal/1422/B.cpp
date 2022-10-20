#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int get(vector<int>x)
{
	sort(x.begin(),x.end());
	int mid=x[x.size()/2],ret=0;
	for (int i=0;i<(int)x.size();i++) ret+=abs(x[i]-mid);
	return ret;
}
int a[N][N];
void Metallica()
{
	ll ans=0;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=(n+1)/2;i++)
	for (int j=1;j<=(m+1)/2;j++)
	{
		bool x=i*2-1!=n,y=j*2-1!=m;
		vector<int>tmp;
		tmp.push_back(a[i][j]);
		if (x) tmp.push_back(a[n-i+1][j]);
		if (y) tmp.push_back(a[i][m-j+1]);
		if (x&&y) tmp.push_back(a[n-i+1][m-j+1]);
		ans+=get(tmp);
	}
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) Metallica();
	
	return 0;
}