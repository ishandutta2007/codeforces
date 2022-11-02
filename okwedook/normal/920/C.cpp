#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<pair<ll, ll>, ll> pp;

int main() { 
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    string s;
    cin >> s;
    s += '1';
    ll m = 1e18, tempm = 1e18;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') m = tempm;
        if (arr[i] > m) {
            cout << "NO";
            return 0;
        }
        tempm = min(tempm, arr[i]);
    }
    cout << "YES";
    //system("pause");
    return 0; 
}