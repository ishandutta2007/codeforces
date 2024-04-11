#include <bits/stdc++.h>

int a[7], sum;

int main() {
    for (int i = 0; i < 6; ++i) scanf("%d", a + i);
    sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
    if(sum & 1) return printf("No"), 0;
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            for (int k = j + 1; k < 6; ++k)
                if((a[i] + a[j] + a[k]) << 1 == sum)
                    return printf("Yes"), 0;
    printf("No");
    return 0;
}