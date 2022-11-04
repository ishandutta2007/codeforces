#include <bits/stdc++.h>


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long n, p10;
    ios::sync_with_stdio(false);
    cin >> n;
    p10 = 1;
    while(p10 <= n)
        p10 *= 10;
    p10 /= 10;
    cout << ((n / p10) + 1) * p10 - n;
    //cin.close();
    //cout.close();
    return 0;
}