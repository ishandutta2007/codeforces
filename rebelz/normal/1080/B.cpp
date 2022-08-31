#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q,l,r,ans;

int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		if(l%2==1){
			ans=(r-l+1)/2;
			if((r-l)%2==0)
				ans-=r;
			cout<<ans<<endl;
		}
		else{
			ans=-(r-l+1)/2;
			if((r-l)%2==0)
				ans+=r;
			cout<<ans<<endl;
		}
	}
	return 0;
}