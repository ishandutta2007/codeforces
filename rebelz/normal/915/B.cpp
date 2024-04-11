#include<iostream>

using namespace std;

int n,pos,l,r,ans;

int main(){
	cin>>n>>pos>>l>>r;
	if(pos<l){
		ans+=l-pos+1;
		if(r!=n)
			ans+=r-l+1;
		cout<<ans<<endl;
	}
	else if(pos>=l&&pos<=r){
		if(l!=1&&r!=n){
			ans+=min(r-pos,pos-l)+1;
			ans+=r-l+1;
			cout<<ans<<endl;
		}
		else if(l==1&&r!=n)
			cout<<r-pos+1<<endl;
		else if(l!=1&&r==n)
			cout<<pos-l+1<<endl;
		else if(l==1&&r==n)
			cout<<0<<endl;
	}
	else if(pos>r){
		ans+=pos-r+1;
		if(l!=1)
			ans+=r-l+1;
		cout<<ans<<endl;
	}
	return 0;
}