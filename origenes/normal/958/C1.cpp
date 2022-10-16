#include <bits/stdc++.h>
using namespace std;
const int maxn=123456;
int a[maxn], n, p;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>p;
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]+x)%p;
	}
	int ans=0;
	for(int i=1; i<n; i++){
		int s=a[i]+((a[n]-a[i])%p+p)%p;
		ans=max(ans, s);
	}
	cout<<ans<<endl;
	return 0;
}