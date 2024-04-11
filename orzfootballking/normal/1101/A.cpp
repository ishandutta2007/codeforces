#include <bits/stdc++.h>
using namespace std;
int main(){
	long long l,r,d,n,ans=0,j;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r>>d;
		ans=d;
		while(ans>=l&&ans<=r)ans+=10000*d;
		if(ans==d){
			cout<<d<<endl;continue;
		}
		for(j=ans-10000*d;j<=ans;j+=d){
			if(j<l||j>r){
				cout<<j<<endl;break;
			}
		}
	}
	return 0;
}