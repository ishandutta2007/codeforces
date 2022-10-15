#include <iostream>
#include <cstdio>

using namespace std;

int n;
int m[2000000];
char x[20];

int main() {
    cin >> n;
    m[0] = 0;
    for (int i = 1; i <= n; i++) {
        sprintf(x, "%i", i);
        m[i] = 999999999;
        for (int j = 0; x[j]; j++) {
            int a = x[j]-'0';
            if (i-a >= 0 && m[i-a]+1 < m[i]) m[i] = m[i-a]+1;
        }
    }
    cout << m[n] << endl;
}