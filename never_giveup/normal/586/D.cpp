#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool q[3][100][100], mas[3][100][2];
int st;

void obnov(int n){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                q[i][j][k] = 0, mas[i][j][0] = 0, mas[i][j][1] = 0;
    for (int it = 0; it < 3; it++){
        int now = 0;
        char a, b;
        for (int j = 0; j < n; j++){
            b = a;
            cin >> a;
            if (a == 's')
                st = it;
            else
            if (j > 0 && (a == '.' || (a != b)) && now > 0){
                int l = j - 1 - now + 1, r = j - 1;
                for (int i = 0; i < j; i++)
                    for (int k = max(0, (l - i + 1) / 2); k <= (r - i) / 2; k++)
                        q[it][i][k] = 1;
                now = 0;
            }
            if (a != '.' && a != 's')
                now++;
        }
        if (now > 0){
            int l = n - 1 - now + 1, r = n - 1;
            for (int i = 0; i < n; i++)
                for (int k = max(0, (l - i + 1) / 2); k <= (r - i) / 2; k++)
                    q[it][i][k] = 1;
            now = 0;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    for (int iter = 0; iter < test; iter++){
        int n, tr;
        cin >> n >> tr;
        obnov(n);
        bool f = 0;
        mas[st][0][1] = 1;
        for (int j = 0; j < n && !f; j++)
        for (int k = 0; k < 2 && !f; k++)
        for (int i = 0; i < 3 && !f; i++)
        if (mas[i][j][k]){
            if ((k == 1 && q[i][j][j]) || q[i][j][j - 1]){
                mas[i][j][k] = 0;
                continue;
            }
            if (j == n - 1 && k == 1){
                cout << "YES" << '\n';
                f = 1;
                break;
            }
            if (i == 0){
                if (k == 1)
                    mas[0][j + 1][0] = 1;
                if (k == 0)
                    mas[1][j][1] = 1, mas[0][j][1] = 1;
            }
            if (i == 1){
                if (k == 1)
                    mas[1][j + 1][0] = 1;
                if (k == 0){
                    mas[0][j][1] = 1;
                    mas[1][j][1] = 1;
                    mas[2][j][1] = 1;
                }
            }
            if (i == 2){
                if (k == 1)
                    mas[2][j + 1][0] = 1;
                if (k == 0)
                    mas[1][j][1] = 1, mas[2][j][1] = 1;
            }
        }
        if (!f)
            cout << "NO" << '\n';
    }
}