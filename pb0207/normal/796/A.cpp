#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+1;
int n,m,k,a[N];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=0x7fffffff;
	for(int i=1;i<=n;++i)
	if(a[i]&&a[i]<=k)ans=min(ans,abs(i-m));
	cout<<ans*10;
}