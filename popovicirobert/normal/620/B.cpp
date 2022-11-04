#include <bits/stdc++.h>
#define long long ll


using namespace std;

int v[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int a, b;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int ans = 0;
    while(a <= b) {
        int aux = a;
        while(aux > 0) {
            ans += v[aux % 10];
            aux /= 10;
        }
        a++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}