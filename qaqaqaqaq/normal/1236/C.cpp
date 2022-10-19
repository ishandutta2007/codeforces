#include<bits/stdc++.h>
using namespace std;

int a[307][307];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (i%2){
				a[n+1-j][i]=(i-1)*n+j;
			} 
			else{
				a[j][i]=(i-1)*n+j;
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}