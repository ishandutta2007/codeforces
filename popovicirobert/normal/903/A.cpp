#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        for(j = 0; j <= x / 3; j++)
            if((x - j * 3) % 7 == 0) {
                   cout << "YES" << endl;
                   x = -1;
                   break;
            }
        if(x > 0)
        cout << "NO" << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}