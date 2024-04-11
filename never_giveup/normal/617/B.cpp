#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q[100][100], a[100];

int main(){
    //ifstream cin("queries.in");
    //ofstream cout("queries.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1)
            q[i][i] = 1;
    }
    for (int len = 1; len < n; len++)
        for (int i = 0; i + len < n; i++){
            int j = i + len;
            int cnt = 0;
            for (int k = i; k < j; k++){
                cnt += a[k];
                if (cnt == 1)
                    q[i][j] += q[k + 1][j];
            }
            cnt += a[j];
            if (cnt == 1)
                q[i][j]++;
        }
    cout << q[0][n - 1];
}