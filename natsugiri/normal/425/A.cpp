#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, K, A[333];

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    int ans = A[0];
    for (int l=0; l<N; l++) {
	for (int r=l+1; r<=N; r++) {
	    vector<int> I, O;
	    for (int i=0; i<l; i++) O.push_back(A[i]);
	    for (int i=l; i<r; i++) I.push_back(A[i]);
	    for (int i=r; i<N; i++) O.push_back(A[i]);
	    sort(I.begin(), I.end());
	    sort(O.rbegin(), O.rend());
	    for (int i=0; i<K && i<(int)I.size() && i<(int)O.size(); i++) {
		if (I[i] < O[i]) I[i] = O[i];
	    }

	    int sum = 0;
	    for (int i=0; i<(int)I.size(); i++) sum += I[i];
	    ans = max(ans, sum);
	}
    }
    

    printf("%d\n", ans);
    return 0;
}