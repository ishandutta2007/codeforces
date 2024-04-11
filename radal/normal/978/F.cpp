#include <bits/stdc++.h>
#include <algorithm>
//#define int long long int
using namespace std;
const int N = 2e5;
long long int ans[N],c[N];
pair<long long int,long long int> p[N],b[N];
void msort1(int l, int r){
	if (r-l <= 1){
		return;
	}
	int m = (l+r)/2;
	msort1(l , m);
	msort1(m , r);
	int p1 = l, p2 = m;
	for (int i=l; i<r; i++){
		if (p2 >= r || (p1 < m && p[p1].first < p[p2].first)){
			b[i].first = p[p1].first;
			b[i].second = p[p1].second;
			p1++; 
		}
		else{
			b[i].first = p[p2].first;
			b[i].second = p[p2].second;
			p2++; 
		}
	}
	for (int i=l; i<r; i++){
		p[i].first = b[i].first;
		p[i].second = b[i].second;
	}
}
 

int main(){
	long long int n,q;
	cin >> n >> q;
	for (int i=0; i<n; i++){
		cin >> p[i].first;
		p[i].second = i;
		c[i] = p[i].first;
	}
	msort1(0,n);
	for (int i=0; i<n; i++){
		ans[p[i].second] = i;
	}
	for (int i=1; i<n; i++){
		if (p[i].first == p[i-1].first){
			ans[p[i].second] = ans[p[i-1].second];
		}
	}
	for (int i=0; i<q; i++){
		long int x,y,z;
		cin >> x >> y;
		x--;
		y--;
		if (c[x] > c[y]){
			ans[x]--;
		}
		else if(c[y] > c[x]){
			ans[y]--;
		}
	}
	for (int i=0; i<n; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
	
}