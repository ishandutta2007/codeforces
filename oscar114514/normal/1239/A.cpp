#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,m;
long long fib[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	fib[0]=fib[1]=2;
	fib[2]=4;
	for(int i=3;i<=max(n,m);i++)fib[i]=(fib[i-1]+fib[i-2])%MOD;
	cout<<(fib[n]+fib[m]-2+MOD)%MOD<<endl;
	return 0;
}