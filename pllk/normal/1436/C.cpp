#include <iostream>

// [?,?,?,?]
//      ^

using namespace std;

int n, x, p;
int f[1111];

#define M 1000000007

typedef long long ll;

void bs() {
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = (left+right)/2;
        if (middle <= p) {
            f[middle] = -1;
            left = middle+1;
        } else {
            f[middle] = 1;
            right = middle;
        }
    }
}

ll ff[1111];
ll ncr[1111][1111];

int main() {
    ff[0] = 1;
    for (int i = 1; i <= 1000; i++) ff[i] = ff[i-1]*i%M;
    ncr[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%M;
        }
    }
    cin >> n >> x >> p;
    bs();
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == -1 && i != p) a++;
        if (f[i] == 1) b++;
    }
    if (a > x-1 || b > n-x) {
        cout << "0\n";
    } else {
        ll r = ncr[x-1][a]*ff[a]%M*ncr[n-x][b]%M*ff[b]%M*ff[n-1-a-b]%M;
        cout << r << "\n";
    }
}