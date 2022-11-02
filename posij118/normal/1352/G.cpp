#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n < 4){
            cout << -1 << endl;
            continue;
        }

        for(int i = n - (n % 2); i>=6; i-=2){
            cout << i << " ";
        }

        cout << 2 << " " << 4 << " ";

        for(int i = 1; i<=n; i+=2){
            cout << i << " ";
        }

        cout << endl;
    }

}