#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int N=1e6;
long long int L[N],R[N],a[N];
pair <string,long long int> ans[N];
void msort(int l,int r){
	int b[N];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<=mid)){
			b[i] = a[p1];
			//L[i] += p2 - mid;
			p1++;
		}
		else{
			b[i] = a[p2];
			//R[i] += mid - p1;
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}
int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		long long int n,m;
		cin>>n>>m;
		if (n == 1){
			cout<<0<<endl;
			continue;
		}
		if (n == 2){
			cout<<m<<endl;
			continue;
		}
		else{
			cout<<2*m<<endl;
		}
	}
	
	
}