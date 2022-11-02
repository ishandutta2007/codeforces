#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x, y, z, w;
        cin >> x >> y >> z >> w;

        if(x == z || y == w){
            cout << abs(x - z) + abs(y-w) << endl;
        }

        else{
            cout << abs(x - z) + abs(y-w) + 2 << endl;
        }
    }
}