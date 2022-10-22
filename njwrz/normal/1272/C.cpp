#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	bool f[300]={};
	char c;
	for(int i=0;i<k;i++){
		cin>>c;
		f[c]=1;
	}
	ll ans=0,t=0;
	for(int i=0;i<n;i++){
		if(!f[s[i]]){
			ans=ans+t*(t+1)/2;
			t=0;
		}else{
			t++;
		}
	}
	ans=ans+t*(t+1)/2;
	cout<<ans;
	return 0;
}