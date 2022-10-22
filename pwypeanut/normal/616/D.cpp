#include <bits/stdc++.h>
using namespace std;

int N, K, arr[500005], cnt[1000005], no;

void ins(int x) {
    cnt[x]++;
    if (cnt[x] == 1) no++;
}

void rem(int x) {
    cnt[x]--;
    if (cnt[x] == 0) no--;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int r = 0, ans = 0, bl = 0, br = 0;
    for (int i = 0; i < N; i++) {
        while (no <= K) {
            if (r == N) {
                if (N - i > ans) {
                    ans = N-i;
                    bl = i;
                    br = N-1;
                }
                goto end;
            }
            ins(arr[r]);
            r++;
        }
        if (r - i - 1 > ans) {
            ans = r-i-1;
            bl = i;
            br = r-2;
        }
        rem(arr[i]);
    }
    end:
    printf("%d %d\n", bl+1, br+1);
}