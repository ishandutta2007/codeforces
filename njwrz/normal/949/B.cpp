#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a;
		while(!(a%2))a+=(n-(a>>1));
		cout<<((a+1)>>1)<<'\n';
	}
	return 0;
}