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


int B, A;
int main() {
    REP (i, 5) {
        scanf("%d", &A);
        B += A;
    }
    if (B && B % 5 == 0) printf("%d\n", B/5);
    else puts("-1");

    return 0;
}