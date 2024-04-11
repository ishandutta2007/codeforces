#include <bits/stdc++.h>

using namespace std;
int n;
bool t[200001];
int a;
int main()
{
    cin >> n;
    a=n+1;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (!t[x]) {
            a--;
        }
        t[x]=true;
    }
    cout << a << endl;
    return 0;
}