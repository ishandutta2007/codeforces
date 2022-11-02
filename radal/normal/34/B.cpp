#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
void sort(int n){
	bool s=false;
	while (not(s)){
		if (n==1){
			break;
		}	
		for (int i=1; i<n; i++){
			if (i==1){
				s=true;
			}
			if (a[i]<a[i-1]){
				swap(a[i],a[i-1]);
				s=false;
			}
		}
	}
}
int main(){
	int n,m,sum=0;
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(n);
	for (int i=0; i<m; i++){
		if (a[i]<0){
			sum+=abs(a[i]);
		}
		else{
			break;
		}
	}
	cout<<sum;
}