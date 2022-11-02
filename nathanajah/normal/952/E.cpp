#include <bits/stdc++.h>
using namespace std;


bool isvocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
    int n;
    scanf("%d", &n);
    int num = 0;
    int numsoft = 0;
    int numhard = 0;
    for (int i = 0; i < n; i++) {

        char c[50];
        char d[50];
        scanf("%s %s", c, d);
        string s1 = c;
        string s2 = d;
        if (s2 == "soft") {
            numsoft++;
        } else {
            numhard++;
        }
    }
    for (int i = 1; i <= 100; i++) {
        int numodd = (i*i + 1) / 2;
        int numeven = (i*i) / 2;
        if ((numodd >= numsoft && numeven >= numhard) || (numodd >= numhard && numeven >= numsoft)) {
            printf("%d\n", i);
            break;
        }

    }
}