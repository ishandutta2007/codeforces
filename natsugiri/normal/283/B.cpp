#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF=1LL<<60;

int N;
LL A[200010];
LL memo[2][200010], dec[200010];
bool use[2][200010];

LL rec(int v, bool inc_flag) {
    if (v<=0 || v>N) return 0;

    if (inc_flag && v==1) return -1; // roop
    if (use[inc_flag][v]) return memo[inc_flag][v];

    use[inc_flag][v]=1;
    memo[inc_flag][v]=-1;

    LL tmp = rec(v+(inc_flag?A[v]:-A[v]), !inc_flag);

    return memo[inc_flag][v]=(tmp==-1?-1:tmp+A[v]);
}

int main() {
    scanf("%d", &N);
    for (int i=2; i<=N; i++) scanf("%lld", A+i);

    for (int i=2; i<=N; i++) {
	A[1]=i;
	rec(i, false);
	printf("%lld\n", memo[false][i]==-1?-1:memo[false][i]+i-1);
	//rec(i, true);
    }
    

    return 0;
}