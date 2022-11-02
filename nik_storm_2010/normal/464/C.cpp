#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 2e5;
const int MOD = 1e9 + 7;

ll value[10], length[10];
string x[N], s;

ll power(ll x, int step)
{
    if (step == 0) return 1;
    ll c = power(x, step / 2);
    c = (c * c) % MOD;
    if (step % 2) c = (c * x) % MOD;
    return c;
}

int main()
{
    getline(cin, s);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < 10; i++) value[i] = i, length[i] = 1;
    x[0] = "0->" + s;
    for (int i = 1; i <= n; i++) getline(cin, x[i]);
    for (int i = n; i >= 0; i--)
    {
        int num = x[i][0] - '0', current_length = x[i].length();
        ll new_value = 0, new_length = 0;
        for (int j = current_length - 1; j >= 3; j--)
        {
            new_value = (new_value + power(10, new_length) * value[x[i][j] - '0']) % MOD;
            new_length = (new_length + length[x[i][j] - '0']) % (MOD - 1);
        }
        value[num] = new_value;
        length[num] = new_length;
    }
    cout << value[0] << endl;
    return 0;
}