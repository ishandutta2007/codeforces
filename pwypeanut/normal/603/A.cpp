#include <bits/stdc++.h>
using namespace std;

int N, val;
char c[100005];

int main() {
    scanf("%d", &N);
    scanf("%s", &c);
    for (int i = 0; i < N - 1; i++) val += c[i] != c[i + 1];
    printf("%d\n", min(val + 3, N));
}