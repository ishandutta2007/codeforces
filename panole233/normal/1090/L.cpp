#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
typedef long long LL;
LL t,n,na,nb,a,b,k;
int main(){
	cin>>t>>n>>a>>b>>k;
	if(n==1){
		if(k==1)cout<<min(t,a)<<endl;
		else cout<<0<<endl;
		return 0;
	}
	na=(n+1)/2;nb=n-na;
	if(a<b){
		swap(a,b);
		swap(na,nb);
	}
	if(k<=na){
		LL sa=1LL*a*na+1LL*b*nb;
		cout<<min(t,(sa/k))<<endl;
		return 0;
	}
	if(k>n){
		cout<<0<<endl;
		return 0;
	}
	if(k==n){
		cout<<min(t,b)<<endl;
		return 0;
	}
	LL kk=k-na;
	if(1LL*(a-1)*kk>=1LL*(b-1)*nb){
		cout<<min(t,min(a,1LL*b*nb/kk))<<endl;
		return 0;
	}
	cout<<min(t,(1LL*a*na+1LL*b*nb)/k)<<endl;
}