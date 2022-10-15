#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,u,a[N],r=2,rx,ry;
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout.precision(40);
	cin>>n>>u;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n-2;++i){
		while(r<n&&a[r]-a[i]<=u)r++;
		r--;
		if(r<=i+1||a[r]-a[i]>u) continue;
		int x=a[r]-a[i+1],y=a[r]-a[i];
		if(!ry){
			rx=x;
			ry=y;
		}
		else if(x*ry>rx*y){
			rx=x;
			ry=y;
		}
	}
	if(ry){
		long double rxx=rx;
		cout<<rxx/ry;
	}
	else cout<<-1;
}