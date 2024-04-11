#include <bits/stdc++.h>
using namespace std;
int a[105],b[105],f[205];
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];f[a[i]]=1;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];f[b[i]]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[a[i]+b[j]]==0){
				cout<<a[i]<<' '<<b[j];return 0;
			}
		}
	}
	return 0;
}