#include <bits/stdc++.h>
using namespace std;

const int c=200002;
int a[c], b[3*c], n, l, lo, hi, mid;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> l;
	for (int i=0; i<n; i++) {
        cin >> a[i];
	}
	for (int i=0; i<n; i++) {
        cin >> b[i+n];
        b[i]=b[i+n]-l;
        b[i+2*n]=b[i+n]+l;
	}
	sort(a, a+n);
	sort(b, b+3*n);
	lo=-1, hi=l/2;
	while (hi-lo>1) {
        mid=(hi+lo)/2;
        int bal=0, jobb=0, cs1=-c, cs2=c;
        for (int i=0; i<n; i++) {
            while (a[i]-b[bal]>mid) {
                bal++;
            }
            while (jobb<3*n && b[jobb]-a[i]<=mid) {
                jobb++;
            }
            jobb--;
            cs1=max(cs1, bal-i-n), cs2=min(cs2, jobb-i-n);
        }
        if (cs1<=cs2) {
            hi=mid;
        } else {
            lo=mid;
        }
	}

	cout << hi << "\n";
    return 0;
}