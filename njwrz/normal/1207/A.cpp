#include <bits/stdc++.h>
using namespace std;
void voi(){
	int n,m,k,t,ans;
	int a,b;
	cin>>n>>m>>k>>a>>b;
	if(a>b){
		t=min(m,n/2);
		n-=t*2;
		m-=t;
		ans=a*t;
		t=min(n/2,k);
		ans+=t*b;
	}else{
		t=min(k,n/2);
		n-=t*2;
		k-=t;
		ans=b*t;
		t=min(n/2,m);
		ans+=t*a;
	}
	cout<<ans<<"\n";
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)voi();
	return 0;
}