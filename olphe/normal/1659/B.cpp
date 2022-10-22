#include "bits/stdc++.h"
using namespace std;

void Solve(){
	int N,M;
	cin>>N>>M;
	string s,t;
	cin>>s;
	vector<int>v(N);
	int amari=M;
	for(int i=0;i<N;i++){
	    int b=s[i]=='1';
	    if(M&1)b^=1;
	    if(b==0&&amari){
	        b=1;
	        v[i]=1;
	        amari--;
	    }
	}
	v.back()+=amari;
	for(int i=0;i<N;i++){
	    if((M-v[i])&1)s[i]^='1'^'0';
	}
	cout<<s<<endl;
	for(auto i:v)cout<<i<<" ";
	cout<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	
	return 0;
}