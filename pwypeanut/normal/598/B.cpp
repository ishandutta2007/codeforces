#include <bits/stdc++.h>
using namespace std;

char s[10005];
int N;

int main() {
    scanf("%s", &s);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        int len = b - a + 1;
        string S = "";
        for (int j = a; j <= b; j++) {
            int pos = ((j - a - c) % len + len) % len + a;
            //printf("%d\n", pos);
            S += s[pos];
        }
        for (int j = a; j <= b; j++) s[j] = S[j - a];
        //printf("%s\n", s);
    }
    printf("%s\n", s);
}