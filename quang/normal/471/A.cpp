#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int sl[10];

void Checkleg() {
    for(int i = 1; i <= 9; i++)
    if(sl[i] >= 4) {
        sl[i] -= 4;
        return;
    }
    cout << "Alien";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    memset(sl, 0, sizeof(sl));
    for(int i = 1; i <= 6; i++) {
        int x;
        cin >> x;
        sl[x]++;
    }
    Checkleg();
    for(int i = 1; i <= 9; i++) {
        if(sl[i] == 2) {
            cout << "Elephant";
            return 0;
        }
        if(sl[i] == 1) {
            cout << "Bear";
            return 0;
        }
    }
    cout << "Alien";
    return 0;
}