#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
bool k[100001];
int p;
int main()
{
    cin >> n;
    p=n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        k[t[i]]=true;
        if (t[i]==p) {
            for (int j=p; j>=1; j--) {
                if (k[j]) {
                    cout << j << " ";
                }
                else {
                    p=j;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}