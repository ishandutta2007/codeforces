#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
LL H[100010], P[100010];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> H[i];
    for (int i=0; i<M; i++) cin >> P[i];

    LL l=-1, r=1LL<<60, m;
    for (;r-l>1;) {
	m = (r+l)/2;
	int k=0;
	for (int i=0; i<N; i++) {
	    int j;
	    for (j=k; j<M; j++) {
		// H[i], P[k], P[j]
		LL d = min(abs(H[i]-P[k]), abs(H[i]-P[j])) + P[j]-P[k];
		if (d>m) break;
	    }
	    k=j;
	}
	if (k==M) r=m; // good
	else l=m; // bad
    }

    cout << r << endl;

    return 0;
}