#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[105];

int main() {
    int n, boo=0, raz;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &p[i]);
        if (i==0) continue;
        if (i==1) {
            raz=p[i]-p[i-1];
            continue;
        }
        if (raz!=p[i]-p[i-1]) {
            boo=1;
        }
    }
    if (boo) printf("%d", p[n-1]);
    else printf("%d", p[n-1]+raz);
}