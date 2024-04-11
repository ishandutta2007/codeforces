#include <bits/stdc++.h>
using namespace std;
long long a[200005],s,t;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		a[i]=a[i-1]+t;
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		s+=t;
		if(s>=a[n]){
			cout<<n<<'\n';s=0;
		}else cout<<n-(upper_bound(a+1,a+n+1,s)-a)+1<<'\n';
	}
	return 0;
}