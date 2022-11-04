#include <bits/stdc++.h>

using namespace std;

int fr[100001];

int cnt[2];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int k1, k2, k3;
    ios::sync_with_stdio(false);
    cin >> k1 >> k2 >> k3;
    fr[k1]++;
    fr[k2]++;
    fr[k3]++;
    int mn = min(k1, min(k2, k3));
    if(mn == 1) {
        cout << "YES";
    }
    else if(mn == 2) {
        if(fr[2] >= 2 || fr[4] == 2) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else if(mn == 3) {
        if(fr[3] == 3) {
            cout << "YES";
        }
        else
            cout << "NO";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}