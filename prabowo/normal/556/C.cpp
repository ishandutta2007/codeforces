#include<bits/stdc++.h>
using namespace std;

int n, k;
vector <int> mat[100002];

int main() {
    scanf("%d %d", &n, &k);
    int m, a;
    for (int i=0; i<k; i++) {
        scanf("%d", &m);
        for (int j=0; j<m; j++) {
            scanf("%d", &a);
            mat[i].push_back(a);
        }
    }

    int ans = 0;
    for (int i=0; i<k; i++) {
        int now = mat[i][0];
        int idx = 0;
        if (now == 1) {
            while (idx < mat[i].size() && now == mat[i][idx]) now++, idx++;
            ans += mat[i].size() - idx;
        } else ans += mat[i].size() - 1;
    }

    printf("%d\n", 2 * ans + k - 1);
    return 0;
}