#include <cstdio>

int p, y;
bool ok() {
    for(int i = 2; i * i <= y && i <= p; ++i)
        if(y % i == 0)
            return 0;
    return 1;
}

int main() {
    scanf("%d%d", &p, &y);
    if(!(y & 1)) y--;
    while(!ok() && y > p)
        y--;
    printf("%d\n", y > p ? y : -1);
}