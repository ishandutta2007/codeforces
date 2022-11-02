#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n, k;
    cin >> n >> k;

    if((n/k)%2==0) cout << "NO";
    else cout << "YES";
}