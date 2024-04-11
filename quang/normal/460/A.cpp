#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n , m;

int main() {
    //fi, fo;
    scanf("%d%d", &n, &m);
    int ngay = 0;
    while(n) {
        ngay++;
        n--;
        if(ngay % m == 0 && ngay) n++;
    }
    cout << ngay;
    return 0;
}