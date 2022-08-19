#include<bits/stdc++.h>

using namespace std;

int n,m,k;

int main(){
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=2*n+2*(m-2);
		n-=4,m-=4;
	}
	cout<<ans<<endl;
	return 0;
}