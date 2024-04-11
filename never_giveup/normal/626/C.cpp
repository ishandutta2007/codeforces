#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    int n, m, a = 0, b = 0, c = 0;
    cin >> n >> m;
    for (int i = 2;; i++){
        if (i % 2 == 0 && i % 3 == 0)
            c++;
        else
        if (i % 2 == 0)
            a++;
        else
        if (i % 3 == 0)
            b++;
        if (min(a, n) + min(b, m) + c >= n + m){
            cout << i;
            return 0;
        }
    }
}