#include <stdio.h>
#include <string.h>

char r[10];

int main(void) {
    int v = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", r);
        for (int j = 1; j < 8; j++)
            if (r[j-1] == r[j]) v = 1;
    }
    if (v == 0) printf("YES\n"); else printf("NO\n");
}