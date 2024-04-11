#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--){
		int n,x,a,b;
		cin>>n>>x>>a>>b;
		int ans=abs(a-b)+x;
		if(ans>=n-1)ans=n-1;
		printf("%d\n",ans);
	}
}