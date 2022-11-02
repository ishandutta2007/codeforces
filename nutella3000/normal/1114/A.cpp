#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x > a) {
        cout << "NO";
        return 0;
    }
    a -= x;
    if (a + b < y) {
        cout << "NO";
        return 0;
    }
    if (a + b + c < y + z) {
        cout << "NO";
    }else cout << "YES";
}