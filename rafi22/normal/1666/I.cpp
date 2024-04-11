#include <cstdio>

using namespace std;

int Scan(int r, int c) {
    printf("SCAN %d %d\n", r, c);
    fflush(stdout);
    int ret; scanf("%d", &ret);
    return ret;
}

int Dig(int r, int c) {
    printf("DIG %d %d\n", r, c);
    fflush(stdout);
    int ret; scanf("%d", &ret);
    return ret;
}

void TestCase() {
    int n, m; scanf("%d%d", &n, &m);
    int A = Scan(1, 1);
    int B = Scan(1, m);
    int C = 2 * (n + m) - A - 4;
    
    int c = (2 * (m + 1) + A - B) / 4;
    int r = (2 * (n + 1) + B - C) / 4;
    
    int d = Scan(1, c);
    int e = Scan(r, m);
    
    int c1 = 1 + (A - d) / 2;
    int c2 = m - (B - d) / 2;
    
    int r1 = 1 + (B - e) / 2;
    int r2 = n - (C - e) / 2;
    
    int q = Dig(r1, c1), w = Dig(r1, c2);
    if(q + w == 2 && c1 != c2)
        return;
    if(q == 1) {
        Dig(r2, c2);
    } else {
        Dig(r2, c1);
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--)
        TestCase();
    return 0;
}