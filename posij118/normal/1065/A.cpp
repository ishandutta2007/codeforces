#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long s, a, b, c;
    cin >> s >> a >> b >> c;

    long long num = s/c;

    int fr = num / a;
    cout << num + fr * b << endl;
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i<t; i++){
        solve();
    }

}