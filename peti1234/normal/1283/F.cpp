#include <bits/stdc++.h>

using namespace std;
const int c=200002;
bool v[c];
int n, ut, fel[c], kezd;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> fel[i];
    }
    kezd=fel[1];
    cout << kezd << "\n";
    fel[n]=kezd;
    v[kezd]=1;
    ut=n;
    if (kezd==n) {
        ut--;
    }
    for (int i=1; i<n; i++) {
        int kov=fel[i+1], pos=ut;
        if (!v[kov]) {
            pos=kov;
        }
        cout << pos << " " << fel[i] << "\n";
        v[pos]=1;
        while (v[ut]) {
            ut--;
        }
    }
    return 0;
}