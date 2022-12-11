#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
#ifdef LOCAL
FILE*FP=freopen("text.in","r",stdin);
//FILE*fp=freopen("text.out","w",stdout);
#endif
signed main(){
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int maxv=-1;
		
		while(n)
		{
			int k=n%10;
			maxv=max(k,maxv);
			n/=10;
		}
		
		cout<<maxv<<"\n";
	}
	return 0;
}