#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;
    int a[100000];
    int numNeg = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (a[i] < 0) numNeg++;
    }

    ll cost = 0;
    for (int i=0; i<n; ++i) {
        if (a[i]<0) cost += -1-a[i];
        else if (a[i]>0) cost += a[i]-1;
        else {
            numNeg = 0;
            cost++;
        }
    }

    if (numNeg%2 == 1) cost+=2;
	
    cout << cost << '\n';
	return 0;
}