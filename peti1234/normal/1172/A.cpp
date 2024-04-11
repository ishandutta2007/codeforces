#include <bits/stdc++.h>
 
using namespace std;
int n;
int a[200001];
int t[200001];
bool p=false;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
    }
    int maxi=0;
    for (int i=1; i<=n; i++) {
        cin  >> t[i];
        a[t[i]]=i;
        if (t[i]!=0) {
            maxi=max(maxi, i-t[i]+1);
        }
        if (a[1]!=0) {
            if (t[i]!=t[i-1]+1) {
                p=true;
            }
        }
    }
    if (a[1]==0) {
        cout << n+maxi << endl;
        return 0;
    }
    if (p) {
        cout << n+maxi << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (a[i]<a[1]) {
            if (a[i]+n-i+2>a[1]) {
                cout << n+maxi << endl;
                return 0;
            }
        }
    }
    cout << maxi-1 << endl;
    return 0;
}