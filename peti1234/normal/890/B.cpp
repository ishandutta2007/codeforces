#include <bits/stdc++.h>

using namespace std;
int n;
int t[200001];
bool v[200001];
int a=n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
        if (!v[t[i]]) {
            a=t[i];
        }
        v[t[i]]=true;
    }
    cout << a << endl;
    return 0;
}