#include <bits/stdc++.h>

using namespace std;

int main(){
        int n;
        cin >> n;
        cout << ((n&(n-1)) ? "NO" : "YES");
        return 0;
}