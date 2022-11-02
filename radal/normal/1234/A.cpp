#include <iostream>
using namespace std;
int main(){
	int q;
	cin>>q;
	long int ans[q];
	for (int i=0; i<q; i++){
		long long int n,k=0,m;
		cin>>n;
		for (int j=0; j<n; j++){
			int x;
			cin>>x;
			k+=x;
		}	
		m=k;
		m/=n;
	
		if (k%n!=0){
			m+=1;
		}
		ans[i]=m;
	}
	for (int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
}