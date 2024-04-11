#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int N, T, C, A[200010];
int main() {
    scanf("%d%d%d", &N, &T, &C);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    int ans = 0;
    int cnt = 0;

    for (int i=0; i<C-1; i++) if (A[i] > T) cnt++;
    for (int i=C-1; i<N; i++) {
	if (A[i] > T) cnt++;
	if (cnt == 0) ans++;
	if (A[i-C+1] > T) cnt--;
    }
    printf("%d", ans);
    return 0;
}