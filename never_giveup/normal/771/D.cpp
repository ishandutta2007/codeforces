#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100, inf = 1e9 + 100;

int n;

string s;

int q[maxn][maxn][maxn][3];

int vl, kl, zl;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'V')
            vl++;
        else
        if (s[i] == 'K')
            kl++;
        else
            zl++;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                for (int l = 0; l < 3; l++)
                    q[i][j][k][l] = inf;
    for (int l = 0; l < 3; l++)
        q[0][0][0][l] = 0;
    for (int sum = 0; sum <= n; sum++)
        for (int v = 0; v <= sum; v++)
            for (int k = 0; v + k <= sum; k++){
                int z = sum - v - k;
                for (int last = 0; last < 3; last++)
                    if (q[v][k][z][last] != inf){
                        if (v < vl){
                            int a = 0, b = 0, c = 0;
                            for (int i = 0; i < n && a != v + 1; i++)
                                if (s[i] == 'V')
                                    a++;
                                else
                                if (s[i] == 'K')
                                    b++;
                                else
                                    c++;
                            q[v + 1][k][z][0] = min(q[v + 1][k][z][0], q[v][k][z][last] + max(0, k - b) + max(0, z - c));
                        }
                        if (k < kl && last != 0){
                            int a = 0, b = 0, c = 0;
                            for (int i = 0; i < n && b != k + 1; i++)
                                if (s[i] == 'V')
                                    a++;
                                else
                                if (s[i] == 'K')
                                    b++;
                                else
                                    c++;
                            q[v][k + 1][z][1] = min(q[v][k + 1][z][1], q[v][k][z][last] + max(0, v - a) + max(0, z - c));
                        }
                        if (z < zl){
                            int a = 0, b = 0, c = 0;
                            for (int i = 0; i < n && c != z + 1; i++)
                                if (s[i] == 'V')
                                    a++;
                                else
                                if (s[i] == 'K')
                                    b++;
                                else
                                    c++;
                            q[v][k][z + 1][2] = min(q[v][k][z + 1][2], q[v][k][z][last] + max(0, k - b) + max(0, v - a));
                        }
                    }
            }
    cout << min(q[vl][kl][zl][0], min(q[vl][kl][zl][1], q[vl][kl][zl][2]));
}