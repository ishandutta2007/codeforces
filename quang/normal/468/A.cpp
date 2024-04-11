#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n;

void inkq() {
    cout << 1 << " * " << 2 << " = " << 2 << endl;
    cout << 3 << " * " << 2 << " = " << 6 << endl;
    cout << 6 << " * " << 4 << " = " << 24 << endl;
    if(n != 4)  cout << 24 << " + " << 0 << " = " << 24 << endl;
     exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    if(n <= 3) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if(n == 4) {
        inkq();
    }
    if(n % 4 == 0) {
        for(int i = 5; i <= n; i += 2)
            cout << i + 1 << " - " << i << " = " << 1 << endl;
        for(int i = 1; i < n / 4 - 1; i++)
            cout << i << " + " << 1 << " = " << i + 1 << endl;
        for(int i = n / 4 - 1; i >= 1; i--)
            cout << i << " - " << 1 << " = " << i - 1 << endl;
        inkq();
    }
    if(n % 4 == 1) {
        for(int i = 6; i <= n; i+= 2)
            cout << i + 1 << " - " << i << " = " << 1 << endl;
        for(int i = 1; i < (n - 5) / 4; i++)
            cout << i << " + " << 1 << " = " << i + 1 << endl;
        for(int i = (n - 5) / 4 ; i >= 1; i--)
            cout << i << " - " << 1 << " = " << i - 1 << endl;
        cout << 4 << " * " << 5 << " = " << 20 << endl;
        cout << 3 << " - " << 1 << " = " << 2 << endl;
        cout << 2 << " + " << 2 << " = " << 4 << endl;
        cout << 4 << " + " << 20 << " = " << 24 << endl;
        if(n != 5)cout << 24 << " + " << 0 << " = " << 24 << endl;
    }
    if(n % 4 == 2) {
        for(int i = 7; i <= n; i += 2)
            cout << i + 1 << " - " << i << " = " << 1 << endl;
        for(int i = 1; i < (n - 6) / 4; i++)
            cout << i << " + " << 1 << " = " << i + 1 << endl;
        for(int i = (n - 6) / 4 ; i >= 1; i--)
            cout << i << " - " << 1 << " = " << i - 1 << endl;
        cout << 6 << " * " << 5 << " = " << 30 << endl;
        cout << 3 << " + " << 4 << " = " << 7 << endl;
        cout << 7 << " - " << 2 << " = " << 5 << endl;
        cout << 5 << " + " << 1 << " = " << 6 << endl;
        cout << 30 << " - " << 6 << " = " << 24 << endl;
        if(n !=6 )cout << 24 << " + " << 0 << " = " << 24 << endl;
    }
    if(n % 4 == 3) {
        for(int i = 8; i <= n; i += 2)
            cout << i + 1 << " - " << i << " = " << 1 << endl;
        for(int i = 1; i < (n - 7) / 4; i++)
            cout << i << " + " << 1 << " = " << i + 1 << endl;
        for(int i = (n - 7) / 4 ; i >= 1; i--)
            cout << i << " - " << 1 << " = " << i - 1 << endl;
        cout << 1 << " + " << 3 << " = " << 4 << endl;
        cout << 4 << " - " << 2 << " = " << 2 << endl;
        cout << 2 << " + " << 4 << " = " << 6 << endl;
        cout << 6 << " + " << 5 << " = " << 11 << endl;
        cout << 11 << " + " << 6 << " = " << 17 << endl;
        cout << 17 << " + " << 7 << " = " << 24 << endl;
        if(n != 7) cout << 24 << " + " << 0 << " = " << 24 << endl;
    }
    return 0;
}