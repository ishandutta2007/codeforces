#include <bits/stdc++.h>
#define ll long long


using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    ll n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if((n / k) % 2 == 0)
        cout << "NO";
    else
        cout << "YES";
    //cin.close();
    //cout.close();
    return 0;
}