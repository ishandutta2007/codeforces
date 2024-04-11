#include <bits/stdc++.h>

using namespace std;
int n;
bool t[10001];
int os;
int h;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (i==x) {
            os++;
        }
        if (i!=x) {
            t[x]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        if (t[i]) {
            h++;
        }
    }
    os+=h/2;
    cout << os;
    return 0;
}