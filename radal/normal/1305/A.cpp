#include <iostream>
#include <algorithm>
using namespace std;
void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}


int main(){
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		int n;
		cin>>n;
		int a[n],b[n];
		for (int j=0; j<n; j++){
			cin>>a[j];
		}
		for (int j=0; j<n; j++){
			cin>>b[j];
		}
		msort(0,n, a);
		msort(0,n, b);
		for (int j=0; j<n; j++){
			cout<<a[j]<<' ';
		}
		cout<<endl;
		for (int j=0; j<n; j++){
			cout<<b[j]<<' ';
		}
	}

	
}