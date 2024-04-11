#include <bits/stdc++.h>

using namespace std;
int t[100001];
int n;
int k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int p=0;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        t[a]++;
        t[b]++;
        if (t[a]==3) {
            p++;
            k=a;
        }
        if (t[b]==3) {
            p++;
            k=b;
        }
    }
    if (p>=2) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (p==1) {
        cout << t[k] << endl;
    for (int i=1; i<=n; i++) {
        if (t[i]==1) {
            cout << k << " " << i << endl;
        }
    }
    }
    else {
        cout << 1 << endl;
        for (int i=1; i<=n; i++) {
            if (t[i]==1) {
                cout << i << " ";
            }
        }
    }
    return 0;
}