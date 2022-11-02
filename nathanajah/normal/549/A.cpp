#include <bits/stdc++.h>
using namespace std;

int n,m;
char c[55][55];

string tmp;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s",c[i]);
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
           tmp = "";
           tmp += c[i][j];
           tmp += c[i][j+1];
           tmp += c[i+1][j];
           tmp += c[i+1][j+1];
           sort(tmp.begin(), tmp.end());
           if (tmp == "acef") {
               ++res;
           }
        }
    }
    printf("%d\n", res);
}