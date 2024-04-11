#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = 1000;

int v[MAXN + 1];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = 1; i <= n; i++) {
       if(v[i] % v[1] > 0) {
           cout << -1;
           return 0;
       }
    }
    cout << 2 * n << endl;
    for(i = 1; i <= n; i++) {
        cout << v[i] << " " << v[1] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}