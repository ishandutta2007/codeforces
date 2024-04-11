#include <iostream>
using namespace std;
int main(){
	int n,m,q;
	cin>>n>>m;
	string s[n],t[m];
	for (int i=0; i<n; i++){
		string j;
		cin>>j;
		s[i]=j;
	}
	for (int i=0; i<m; i++){
		string j;
		cin>>j;
		t[i]=j;
	}
	cin>>q;
	string ans[q];
	for (int i=0; i<q; i++){
		int y;
		cin>>y;
		if (y%n==0){
			ans[i]=s[n-1];
		}
		else{
			ans[i]=s[y%n-1];
		}
		if (y%m==0){
			ans[i]+=t[m-1];
		}
		else{
			ans[i]+=t[y%m-1];
		}
	}
	for (int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
		
}