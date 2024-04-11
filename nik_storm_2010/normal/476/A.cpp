#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = n / 2; i >= 0; i--) if ((i + (n - i * 2)) % m == 0) {
        printf("%d\n", i + (n - i * 2));
        return 0;
    }
    puts("-1");
    return 0;
}