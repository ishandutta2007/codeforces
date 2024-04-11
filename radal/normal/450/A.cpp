#include <iostream>
using namespace std;
int main(){
	int x,n,m,k,k2,j;
	cin>>n>>m;
	cin>>x;
	j=1;
	k=x/m;
	if (x%m==0){
		k-=1;
	}
	for (int i=2; i<=n; i++){
		cin>>x;
		k2=x/m;
		if (x%m==0){
			k2-=1;
		}
		if (k2>=k){
			j=i;
			k=k2;
		}
	}
	cout<<j;
}