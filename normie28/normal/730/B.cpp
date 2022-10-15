#include <bits/stdc++.h>
using namespace std;
int nanya(int a, int b) {
	cout << "? " << a <<" "<< b << endl;
	char s;
	cin >> s;
	if (s=='>') return a;
	else return b;
}
int main () {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int min=n,max=n;
		if (n%2==0) {
			max=nanya(n,n-1);
			min=2*n-1-max;
		} 
		n=(n-1)/2;
		for (int i=1;i<=n;i++) {
			int maxx,minn;
			maxx=nanya(2*i,2*i-1);
			minn=4*i-1-maxx;
			max=nanya(max,maxx);
			min=min+minn-nanya(min,minn);
		}
		cout << "! " << min << " " << max << endl;
	}
}