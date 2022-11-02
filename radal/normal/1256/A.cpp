#include <iostream>
using namespace std;
int main(){
	int q;
	cin>>q;
	string ans[q];
	for (int i=0; i<q; i++){
		long long int a,b,n,S;
		cin>>a>>b>>n>>S;
		if (a*n+b<S){
			ans[i]="NO";
			continue;
		}
		else{
			if (S%n>b){
				ans[i]="NO";
			}
			else{
				ans[i]="YES";
			}
		}
	}
	for (int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
}