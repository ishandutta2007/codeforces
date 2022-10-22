#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f; 
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	int ans=0;
	int t=min(b,c);
	if(e>f){
		int p=min(a,d);
		ans+=p*e;
		d-=p;
		p=min(d,t);
		ans+=p*f;
	}else{
		int p=min(d,t);
		ans+=p*f;
		d-=p;
		p=min(a,d);
		ans+=p*e;
	}
	cout<<ans;
	return 0;
}