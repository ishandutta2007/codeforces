#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z,d;
    cin >> x >> y >> z >> d;
    cout << max(abs(z-x),abs(d-y));
    return 0;
}