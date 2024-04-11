#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 20;

int n, m, q[maxn][maxn], c[maxn][maxn];

int a[maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> q[i][j], q[i][j]--;
    for (int s1 = 0; s1 < m; s1++)
        for (int s2 = s1; s2 < m; s2++){
            bool is = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    c[i][j] = q[i][j];
            for (int i = 0; i < n && is; i++){
                int cnt = 0;
                for (int j = 0; j < m && is; j++){
                    if (j != s1 && j != s2){
                        if (c[i][j] != j)
                            for (int k = j + 1; k < m; k++)
                            if (c[i][k] == j){
                                cnt++;
                                swap(c[i][k], c[i][j]);
                                if (cnt > 1)
                                    is = 0;
                                break;
                            }
                    }
                    else
                    if (j == s1){
                        if (c[i][j] != s2)
                            for (int k = j + 1; k < m; k++)
                            if (c[i][k] == s2){
                                cnt++;
                                swap(c[i][k], c[i][j]);
                                if (cnt > 1)
                                    is = 0;
                                break;
                            }
                    }
                    else{
                        if (c[i][j] != s1)
                            for (int k = j + 1; k < m; k++)
                            if (c[i][k] == s1){
                                cnt++;
                                swap(c[i][k], c[i][j]);
                                if (cnt > 1)
                                    is = 0;
                                break;
                            }
                    }
                }
            }
            if (is){
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}