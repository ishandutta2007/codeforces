#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long ans = (n/2);
    if (n%2 == 1) ans -= n;
    cout << ans << endl;
    return 0;
}