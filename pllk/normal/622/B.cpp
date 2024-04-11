#include <iostream>
#include <cstdio>

using namespace std;

int h, m, a;

int main() {
    if (scanf("%d:%d", &h, &m));
    if (scanf("%d", &a));
    for (int i = 0; i < a; i++) {
        m++;
        if (m == 60) {
            h++;
            m = 0;
        }
        if (h == 24) h = 0;
    }
    printf("%02d:%02d\n", h, m);
}