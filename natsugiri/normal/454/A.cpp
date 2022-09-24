#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


#define REP(i,n) for(int i=0; i<int(n); i++)

int N;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	REP (j, N) putchar(abs(i-N/2) + abs(j-N/2) > N/2 ? '*' : 'D');
	putchar('\n');
    }
    return 0;
}