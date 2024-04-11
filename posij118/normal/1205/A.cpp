#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(!(n % 2)){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    for(int i = 0; i<n; i++){
        cout << 2*i + 1 + (i % 2) << " ";
    }

    for(int i = 0; i<n; i++){
        cout << 2*i + 2 - (i % 2) << " ";
    }

}