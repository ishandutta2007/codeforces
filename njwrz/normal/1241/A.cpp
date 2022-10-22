#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n<4){
			cout<<4-n;
		}else cout<<n%2;
		puts("");
	}
	return 0;
}