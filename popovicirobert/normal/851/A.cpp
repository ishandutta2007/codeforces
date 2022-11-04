#include <bits/stdc++.h>
#define ll long long


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, t;
    ios::sync_with_stdio(false);
    cin >> n >> k >> t;
    if(t < k)
        cout << t;
    else if(t <= n)
        cout << k;
    else
        cout << k - (t - n);
    //cin.close();
    //cout.close();
    return 0;
}