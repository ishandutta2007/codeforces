#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int n;

void go(long long x) {
    if (x <= n) a.push_back((int) x); else return;
    go(x * 10 + 4);
    go(x * 10 + 7);
}

int main() {
    scanf("%d", &n);
    go(0);
    sort(a.begin(), a.end());
    printf("%d\n", (int) (lower_bound(a.begin(), a.end(), n) - a.begin()));
}