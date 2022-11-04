#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    long long a, b;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    long long ans = 1;
    if(b - a <= 10) {
        for(long long i = a + 1; i <= b; i++)
           ans = (ans * (i % 10)) % 10;
    }
    else
        ans = 0;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}