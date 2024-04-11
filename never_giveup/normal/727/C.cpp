#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int n;

int q[maxn];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    int v1, v2, v3;
    cout << "? 1 2" << endl;
    cin >> v1;
    cout << "? 1 3" << endl;
    cin >> v2;
    cout << "? 2 3" << endl;
    cin >> v3;
    q[0] = (v1 + v2 - v3) / 2;
    q[1] = v1 - q[0];
    q[2] = v2 - q[0];
    for (int i = 3; i < n; i++){
        cout << "? 1 " << i + 1 << endl;
        int x;
        cin >> x;
        q[i] = x - q[0];
    }
    cout << '!';
    for (int i = 0; i < n; i++)
        cout << ' ' << q[i];
    cout << endl;
}