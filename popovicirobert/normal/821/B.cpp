#include <bits/stdc++.h>


using namespace std;


int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    //int ;
    long long m,b,i,y1,x2,x,y;
    ios::sync_with_stdio(false);
    cin >> m >> b;
    y1 = b;
    x2 = m * b;
    long long ans = 0;
    for(i = 0; i <= y1; i++) {
        x = (b - i) * m;
        if(ans < (x + 1) * (i * (i + 1)) / 2 + (i + 1) * (x * (x + 1)) / 2)
            ans = (x + 1) * (i * (i + 1)) / 2 + (i + 1) * (x * (x + 1)) / 2;
    }
    for(i = 0; i <= x2; i++) {
        y = (b * m - i) / m;
        if(ans < (i + 1) * (y * (y + 1)) / 2 + (y + 1) * (i * (i + 1)) / 2)
            ans = (i + 1) * (y * (y + 1)) / 2 + (y + 1) * (i * (i + 1)) / 2;
    }
    cout << ans;
    //cin.close();
   // cout.close();
    return 0;
}