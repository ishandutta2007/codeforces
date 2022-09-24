#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const int BASE = 4010;
const int INF = 1<<29;
int N, A[4010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<2*N; i++) scanf("%*d.%d", A+i);

    sort(A, A+N);

    int sum = 0, cnt = 0, zero = 0;
    for (int i=0; i<2*N; i++) {
	sum += A[i];
	if (A[i]) cnt++;
	else zero++;
    }
    int l = max(0, N-zero), h = min(cnt, N);
    //printf("%d %d\n", l, h);

    int ans = INF;
    for (int i=l; i<=h; i++) {
	ans = min(ans, abs(sum - i*1000));
    }

    printf("%d.%03d\n", ans/1000, ans % 1000);
    

    return 0;
}