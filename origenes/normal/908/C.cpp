#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1234;
int n, r;
int x[maxn];
double h[maxn];
int main(){
	cout<<fixed<<setprecision(10);
	cin>>n>>r;
	for(int i=0; i<n; i++)
		cin>>x[i];
	h[0]=r;
	for(int i=1; i<n; i++){
		h[i]=r;
		for(int j=0; j<i; j++){
			double diff=abs(x[i]-x[j]);
			if(diff>2*r) continue;
			h[i]=max(sqrt(4*r*r-diff*diff)+h[j], h[i]);
		}
	}
	for(int i=0; i<n; i++)
		cout<<h[i]<<' ';
	cout<<endl;
	return 0;
}