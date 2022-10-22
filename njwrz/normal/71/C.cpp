#include <bits/stdc++.h>
using namespace std;
bool a[500005];int n;
bool check(int p){
	int f;
	for(int i=1;i<=p;i++){
		f=1;
		for(int j=i;j<n+i;j+=p){
			if(!a[j]){
				f=0;break;
			}
		}
		if(f){
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(i>=3){
				if(check(n/i)){
					cout<<"YES";return 0;
				}
			}
			if(n/i>=3){
				if(check(i)){
					cout<<"YES";return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}