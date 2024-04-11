#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dl;
int n;
int q[100000];
int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    for (int i = 0; i < n; i++){
        if (i == 0)
            cout << q[i + 1] - q[i];
        else
        if (i == n - 1)
            cout << q[i] - q[i - 1];
        else
            cout << min(q[i + 1] - q[i], q[i] - q[i - 1]);
        cout << ' ' << max(q[n - 1] - q[i], q[i] - q[0]) << '\n';
    }
}