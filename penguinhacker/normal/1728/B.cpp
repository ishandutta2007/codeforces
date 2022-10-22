#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int s=1;
	    if (n%2) {
	        cout << "1 2 3 ";
	        s+=3;
	    }
	    for (; s<n-1; s+=2)
	        cout << s+1 << " " << s << " ";
	    cout << n-1 << " " << n << "\n";
	}
	return 0;
}