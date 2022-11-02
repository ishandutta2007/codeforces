#include <cstdio>

using namespace std;
const int N = 2e6;

bool used[N];

int main() {
    int a, m;
    scanf("%d %d", &a, &m);
    for (a %= m; !used[a]; a = (a + (a % m)) % m) {
        used[a] = true;
        if (a == 0) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}