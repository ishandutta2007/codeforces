#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
char a[N];

int main() {
    scanf("%d", &n);
    scanf("%s", a + 1);
    sort(a + 1, a + n + 1);
    printf("%s\n", a + 1);
    return 0;
}