#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 301;

bool q[maxn][maxn];

bool a[maxn][maxn][8], b[maxn][maxn][8];

int t[maxn];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int sta = 150, stb = 150;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < t[0]; i++)
        q[sta][stb + i] = 1;
    a[sta][stb + t[0] - 1][0] = 1;
    for (int it = 1; it < n; it++){
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                for (int type = 0; type < 8; type++)
                if (a[i][j][type]){
                    if (type == 0){
                        for (int w = 1; w <= t[it]; w++)
                            q[i - w][j + w] = 1, q[i + w][j + w] = 1;
                        b[i - t[it]][j + t[it]][7] = 1;
                        b[i + t[it]][j + t[it]][1] = 1;
                    }
                    if (type == 1){
                        for (int w = 1; w <= t[it]; w++)
                            q[i][j + w] = 1, q[i + w][j] = 1;
                        b[i][j + t[it]][0] = 1;
                        b[i + t[it]][j][2] = 1;
                    }
                    if (type == 2){
                        for (int w = 1; w <= t[it]; w++)
                            q[i + w][j + w] = 1, q[i + w][j - w] = 1;
                        b[i + t[it]][j + t[it]][1] = 1;
                        b[i + t[it]][j - t[it]][3] = 1;
                    }
                    if (type == 3){
                        for (int w = 1; w <= t[it]; w++)
                            q[i + w][j] = 1, q[i][j - w] = 1;
                        b[i + t[it]][j][2] = 1;
                        b[i][j - t[it]][4] = 1;
                    }
                    if (type == 4){
                        for (int w = 1; w <= t[it]; w++)
                            q[i + w][j - w] = 1, q[i - w][j - w] = 1;
                        b[i + t[it]][j - t[it]][3] = 1;
                        b[i - t[it]][j - t[it]][5] = 1;
                    }
                    if (type == 5){
                        for (int w = 1; w <= t[it]; w++)
                            q[i][j - w] = 1, q[i - w][j] = 1;
                        b[i][j - t[it]][4] = 1;
                        b[i - t[it]][j][6] = 1;
                    }
                    if (type == 6){
                        for (int w = 1; w <= t[it]; w++)
                            q[i - w][j - w] = 1, q[i - w][j + w] = 1;
                        b[i - t[it]][j - t[it]][5] = 1;
                        b[i - t[it]][j + t[it]][7] = 1;
                    }
                    if (type == 7){
                        for (int w = 1; w <= t[it]; w++)
                            q[i - w][j] = 1, q[i][j + w] = 1;
                        b[i - t[it]][j][6] = 1;
                        b[i][j + t[it]][0] = 1;
                    }
                }
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                for (int type = 0; type < 8; type++)
                    a[i][j][type] = b[i][j][type], b[i][j][type] = 0;
    }
    int answer = 0;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            if (q[i][j])
                answer++;
    cout << answer;
}