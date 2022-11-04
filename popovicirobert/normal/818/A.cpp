#include <bits/stdc++.h>


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long  n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    long long a = (n / 2) / (k + 1);
    cout <<  a << " " << a * k << " " << n - a * (k + 1);
    //cin.close();
    //cout.close();
    return 0;
}