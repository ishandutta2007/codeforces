#include <iostream>
#include <algorithm>

int a[4];
int main() {
    for (int i = 0; i < 3; i++)
        scanf("%d", a + i);
    std::sort(a , a + 3);
    if (a[2] >= a[0] + a[1]) printf("%d", a[2] - (a[0] + a[1]) + 1);
    else printf("0");
}