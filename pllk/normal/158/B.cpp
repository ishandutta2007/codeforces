#include <stdio.h>

int n;
int s[5];

int main(void) {
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%i", &a);
        s[a]++;
    }
    int t = s[4]+s[3];
    s[1] -= s[3];
    t += s[2]/2;
    if (s[2]%2 == 1) {
        t++;
        s[1] -= 2;
    }
    if (s[1] > 0) t += (s[1]-1)/4+1;
    printf("%i\n", t);
}