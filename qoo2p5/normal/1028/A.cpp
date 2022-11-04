#include<bits/stdc++.h>
using namespace std;
int main() {

    int n,m;
    cin>>n>>m;
    int x = 0, y = 0, c = 0;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++) {
            
            if (a[j] == 'W') continue;
            
            c++;
            x += i;
            y += j;
        }
    }

    x /= c;
    y /= c;
    cout << x+1 << " " << y + 1 << endl;
            

}