#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int di = (k - 1) / (n - 1);
        int mo = (k - 1) % (n - 1);

        cout << di * n + mo + 1 << endl;

    }

}