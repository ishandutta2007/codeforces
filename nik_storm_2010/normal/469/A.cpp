#include <cstdio>

using namespace std;
const int N = 200;

bool used[N];

int main() {
    int n;
    scanf("%d", &n);
    int k1, k2;
    scanf("%d", &k1);
    for (int i = 1; i <= k1; i++) {
        int x;
        scanf("%d", &x);
        used[x] = true;
    }
    scanf("%d", &k2);
    for (int i = 1; i <= k2; i++) {
        int x;
        scanf("%d", &x);
        used[x] = true;
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) ans &= used[i];
    puts(ans ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}