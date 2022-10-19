#include<bits/stdc++.h>
using namespace std;

int t,n;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n>>s;
		int r=0;
		for (int i=0;i<n;++i){
			if (s[i]=='1'){
				r=max(r,max(n-i,i+1));
			}
		}
		cout<<max(2*r,n)<<endl;
	}
	return 0;
}