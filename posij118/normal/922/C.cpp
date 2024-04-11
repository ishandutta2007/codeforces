#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    long long int m=50;
    cin >> n >> k;

    for(int i=1; i<=min(m, k); i++){
        if((n%i)!=(i-1)){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

}