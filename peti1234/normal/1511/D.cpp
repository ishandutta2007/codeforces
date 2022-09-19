#include <bits/stdc++.h>

using namespace std;
const int c=28;
int n, k, ert=0;
bool v[c][c];
string s;
char p='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=k*k; i++) {
        s+=p+ert;
        for (int j=0; j<k; j++) {
            int kov=(ert+j)%k;
            if (!v[ert][kov]) {
                v[ert][kov]=1;
                ert=kov;
                break;
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout << s[i%(k*k)];
    }
    cout << "\n";
    return 0;
}