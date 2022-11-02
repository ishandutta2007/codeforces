#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,p,t=0;
	cin>>n;
	int l[n],r[n];
	for (int i=0; i<n; i++){
		cin>>l[i]>>r[i];
	}
	cin>>p;
	for (int i=0; i<n; i++){
		if (p<=r[i]){
			t++;
		}
	}
	cout<<t;
}