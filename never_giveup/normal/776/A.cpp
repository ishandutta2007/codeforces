#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int n;
    cout << a << ' ' << b << '\n';
    cin >> n;
    for (int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;
        if (s == a){
            a = t;
        }
        else
            b = t;
        cout << a << ' ' << b << '\n';
    }
}