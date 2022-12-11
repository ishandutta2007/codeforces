#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << -1;
    }
    else{
        for(int i = 2;i<=n;i+=2){
            cout << i << " " << i - 1 << " ";
        }
    }
    return 0;
}