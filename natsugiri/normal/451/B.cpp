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


int N;
int A[100011];
pair<int, int> P[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);
    P[N] = make_pair(-9, -9);


    int l, r;
    int k = 0;
    for (; k < N && P[k].second == k; k++) ;
    if (k == N) {
	puts("yes\n1 1");
	return 0;
    }

    l = k+1;
    for (; k < N && P[k].second-1 == P[k+1].second; k++) ;

    if (k == N-1) {
	r = N;
	k = N;
    } else {
	r = k+1;
	k++;
    }

    for (; k < N && P[k].second == k; k++) ;

    if (k < N) {
	puts("no");
//	printf("%d %d\n", l, r);
    } else {
	puts("yes");
	printf("%d %d\n", l, r);
    }


    return 0;
}