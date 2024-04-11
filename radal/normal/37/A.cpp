#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
void sort(int n){
	bool f=true;
	while (f){
		if (n==1){
			break;
		}
		for(int i=1; i<n; i++){
			if (i==1){
				f=false;
			}
			if (a[i]<a[i-1]){
				swap(a[i],a[i-1]);
				f=true;
			}
			
		}
	}
}
int main(){
	int n,l=1;
	cin>>n;
	int t=n;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(n);
	int l1=1;
	for (int i=0; i<n-1; i++){
		if (a[i]!=a[i+1]){
			if (l<l1){
				l=l1;
			}
			l1=1;
		}
		if (a[i]==a[i+1]){
			l1+=1;
			t-=1;
		}
	}
	if (l1>l){
		l=l1;
	}
	cout<<l<<' '<<t;
}