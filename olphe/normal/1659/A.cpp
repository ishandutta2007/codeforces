#include "bits/stdc++.h"
using namespace std;

void Solve(){
	int a,b,c;
	cin>>a>>b>>c;
	string s;
	for(int i=0;i<c+1;i++){
		for(int j=0;j<b/(c+1);j++){
			s.push_back('R');
		}
		if(b%(c+1)>i)s.push_back('R');
		s.push_back('B');
	}
	s.pop_back();
	cout<<s<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	
	return 0;
}