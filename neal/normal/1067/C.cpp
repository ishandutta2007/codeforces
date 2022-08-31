#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    for (int x = 0; N > 0; x++)
        for (int y = 0; y < 3; y++)
            if (x % 2 == y % 2 && N-- > 0)
                printf("%d %d\n", x, y);
}