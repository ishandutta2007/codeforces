#include <bits/stdc++.h>
using namespace std;
 #define MOD 998244353
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
 
long long t,k,n,m, i,j,jj,mid,a,b,root;
vector <long long> cards;
long long p[2501],c[2501],res[2501];
vector <long long> child[2501];
vector<long long> ord[2501];
void dfs(int x)
{
	int a;
	for (int i=0; i<child[x].size();i++) 
	{
		a=child[x][i];
	dfs(a);
	for (int j=0;j<ord[a].size();j++) ord[x].push_back(ord[a][j]);
	}
	if (c[x]>ord[x].size()) {cout<<"NO"; exit(0);}
	ord[x].insert(ord[x].begin()+c[x],x);
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   for (i=1;i<=n;i++) {cin>>p[i]>>c[i]; if (!p[i]) root=i; else {child[p[i]].push_back(i);}}
	dfs(root);
	for (i=0;i<n;i++) res[ord[root][i]]=i+1;
	cout<<"YES"<<endl;
	for (i=1;i<=n;i++) cout<<res[i]<<' ';
	
}
/*
I don't want a lot for Christmas
There is just one thing I need
I don't care about bi D
That I toang yesterday
I just want you for my own
More than you could ever know
Make my wish come true oh
All I want for Christmas is tm
*/