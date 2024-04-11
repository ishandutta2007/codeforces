#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)


int N, M;
double P(int k) { // at most k of M in N times
    return pow((double)k/M, N);
}

// sum (i+1) { ((i+1)/M)^N - (i/M)^N }

int main() {
    scanf("%d%d", &M, &N);

    double ans = 0;
    REP (i, M) ans += (i+1) * (P(i+1) - P(i));

    printf("%.9f\n", ans);

    return 0;
}