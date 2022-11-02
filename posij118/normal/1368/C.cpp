#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;

    cout << 7*n + 8 << endl;

    for(int i = 0; i<=n; i++){
        int x = 2*i;

        int dy = 2*(i % 2) - 1;

        cout << x << " " << 0 << endl;
        cout << x << " " << dy << endl;
        cout << x << " " << 2*dy << endl;
        cout << x + 1 << " " << 0 << endl;
        cout << x + 1 << " " << 2*dy << endl;
        cout << x + 2 << " " << dy << endl;
        cout << x + 2 << " " << 2*dy << endl;

    }

    cout << 2*n + 2 << " " << 0 << endl;

}