#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

int A[4];
int main() {
    REP (i, 4) scanf("%d", A+i);
    bool yes = false;
    if (A[0] <= A[2] && A[1] <= A[3]) yes = true;
    else if (A[0] + A[1] <= max(A[2], A[3])) yes = true;
    puts(yes? "Polycarp": "Vasiliy");
    return 0;
}