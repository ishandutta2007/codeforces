#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dl;
typedef long double ld;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ld m[5], w[5], h1, h2, sum = 0, mx[5];
    for (int i = 0; i < 5; i++)
        cin >> m[i];
    mx[0] = 500;
    mx[1] = 1000;
    mx[2] = 1500;
    mx[3] = 2000;
    mx[4] = 2500;
    for (int i = 0; i < 5; i++)
        cin >> w[i];
    cin >> h1 >> h2;
    sum = h1 * 100.0 - h2 * 50.0;
    for (int i = 0; i < 5; i++)
        sum += max(0.3 * mx[i], (1.0 - m[i] / 250.0) * mx[i] - 50.0 * w[i]);
    cout << round(sum);
}