#include <bits/stdc++.h>
#define ll long long


using namespace std;

int fr[2];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int s = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        s += x % 2;
        fr[x % 2]++;
    }
    if(s % 2 == 1)
        cout << "First";
    else {
        if(fr[1] == 0)
            cout << "Second";
        else
            cout << "First";
    }
    //cin.close();
    //cout.close();
    return 0;
}