#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;cout<<n<<'\n';
	string t;
	t=s.substr(0,k);string p=t;
	for(int i=k;i<n;i++){
		t+=t[i-k];
	}
	if(t>=s){
		cout<<t;return 0;
	}
	p[k-1]++;
	int l=k-1;
	while(p[l]>'9'){
		p[l]-=10;
		p[l-1]++;
		l--;
	}
	for(int i=k;i<n;i++){
		p+=p[i-k];
	}
	cout<<p;
	return 0;
}