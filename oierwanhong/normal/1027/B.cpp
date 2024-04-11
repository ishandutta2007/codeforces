#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,q,x,y,ans;
	cin>>n>>q;
	while(q--){
		ans=0;
		cin>>x>>y;
		if((x+y)%2==0){
			ans+=(x-1)/2*n+(x-1)%2*(n/2.0+0.5);
			ans+=(y+x%2)/2;
		}
		else{
			ans+=n*n/2.0+0.5;
			ans+=(x-1)/2*n+(x-1)%2*(n/2);
			ans+=(y+!(x%2))/2;
		}
		cout<<ans<<endl;
	}
}