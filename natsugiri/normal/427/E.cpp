#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, A[1000100];
LL r_sum, l_sum, r_cnt, l_cnt;;

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    sort(A, A+N);

    for (int i=N-1; i>0; i-=M) r_sum += A[i];
    r_cnt = N-1;

    LL ans = 2 * (r_sum - (r_cnt+M-1)/M * A[0]) ;
    for (int i=1; i<N; i++) {
	if (l_cnt % M == 0) l_sum += A[i-1];
	l_cnt++;
	r_cnt--;
	if (r_cnt % M == 0) r_sum -= A[i];

	LL tmp = r_sum - (r_cnt+M-1)/M * A[i] + (l_cnt+M-1)/M * A[i] - l_sum;
	ans = min(ans, 2*tmp);
    }

    cout << ans << endl;

    return 0;
}