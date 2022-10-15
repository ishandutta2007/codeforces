#include <cstdio>
#include <vector>

using namespace std;

#define M 1000000

int n;
int t[1010101];
vector<int> v;
int d;

int main() {
    if (scanf("%i", &n));
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%i", &x));
        t[x-1] = 1;
    }
    for (int i = 0; i < M; i++) {
        if (!t[i]) continue;
        if (!t[M-i-1]) {
            v.push_back(M-i);
            continue;
        }
        d++;
    }
    for (int i = 0; i < M/2; i++) {
        if (d == 0) break;
        if (!t[i] && !t[M-i-1]) {
            v.push_back(i+1);
            v.push_back(M-i);
            d -= 2;
        }
    }
    printf("%i\n", (int)v.size());
    for (int i = 0; i < v.size(); i++) {
        printf("%i ", v[i]);
    }
    printf("\n");
}