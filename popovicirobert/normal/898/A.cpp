#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int a = (n / 10) * 10;
    int b = a + 10;
    if(n - a <= b - n)
        cout << a;
    else
        cout << b;
    //cin.close();
    //cout.close();
    return 0;
}