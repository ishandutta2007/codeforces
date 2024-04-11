#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b,c,d,k;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		int u=(a-1)/c+1,v=(b-1)/d+1;
		if (u+v<=k){
			cout<<u<<" "<<v<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}