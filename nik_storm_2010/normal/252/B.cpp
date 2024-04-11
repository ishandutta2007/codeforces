#include<iostream>

using namespace std;
const int N = 100000 + 10;

int a[N], n;

bool check(int x, int y) {
    bool flag1 = true, flag2 = true;
    int w;
    swap(a[x], a[y]);
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) flag1 = false;
        if (a[i - 1] < a[i]) flag2 = false;
    }
    swap(a[x], a[y]);
    return (flag1 || flag2);
}

int main() {
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i != 1 && a[i] != a[i-1]) flag = false;
    }
    if (flag == false ) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            if (a[i] != a[j]) {
                bool res = check(i, j);
                if (res == false) {
                    cout << i << " " << j;
                    return 0;
                }
            }
    }
    cout << -1;
    return 0;
}