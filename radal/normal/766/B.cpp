#include <bits/stdc++.h>
#include <algorithm>
//#define int long long int
using namespace std;
const int N = 1e5;
long long int a[N],b[N];
//pair<long long int,long long int> p[N],b[N];
void msort(int l, int r, long long int arr[N]){
	if (r-l <= 1){
		return;
	}
	int m = (l+r)/2;
	msort(l , m, arr);
	msort(m , r, arr);
	int p1 = l, p2 = m;
	for (int i=l; i<r; i++){
		if (p2 >= r || (p1 < m && a[p1] < a[p2])){
			a[i] = arr[p1];
			p1++; 
		}
		else{
			a[i] = arr[p2];
			p2++; 
		}
	}
	for (int i=l; i<r; i++){
		arr[i] = a[i];
	}
}
 

int main(){
	long long int n,t;
	string s;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i=2; i<n; i++){
		if (a[i]<a[i-1]+a[i-2]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO";
}