#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    ll n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * ((m + a - 1) / a);
    //system("pause");     
    return 0; 
}