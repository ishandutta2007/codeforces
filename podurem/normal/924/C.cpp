#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
      
#define TASK "linkedmap"

using namespace std;

const int dd = (int)1e5 + 1;

int A[dd], P[dd];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    	cin >> A[i];

    set<int> F;
    P[0] = 1;
    int uP = 1;
    for (int i = 1; i < n; ++i) {
    	while (A[i] > uP) {
    		P[*F.rbegin()] = 1;
    		F.erase(*F.rbegin());
    		uP++;
    	}
    	if (A[i] == uP) P[i] = 1, uP++;
    	else F.insert(i);
    }

    long long ans = 0;
    uP = 1;
    for (int i = 1; i < n; ++i) {
    	if (P[i]) ++uP;
    	ans += uP - A[i] - 1;
    }
    cout << ans << "\n";
    return 0;
}