#include <bits/stdc++.h>
using namespace std;

int main(){
    int t1, t2, t3, twal, telv, x, y, z;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    twal = t1 * abs(x - y);
    telv = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;

    
    if(telv <= twal) cout << "YES";
    else cout << "NO";


}