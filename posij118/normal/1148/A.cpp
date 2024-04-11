#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >>c;

    if(a > b){
        long long x = min(a - 1, b);
        cout << 2*c + 2*x + 1;
    }

    else if(a < b){
        int x = min(a, b - 1);
        cout << 2*c + 2*x + 1;
    }

    else cout << a + b + 2*c;

}