#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)


int N;
pair<int, int> A[3011];;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &A[i].first);
	A[i].second = i;
    }
    sort(A, A+N);

    vector<int> P, Q;
    REP (i, N) {
	if (A[i].second != i) {
	    P.push_back(i);
	    Q.push_back(A[i].second);
	    swap(A[i], A[A[i].second]);
	    i--;
	}
    }

    printf("%d\n", P.size());
    for (int i=P.size(); i--;) 
	printf("%d %d\n", P[i], Q[i]);

    return 0;
}