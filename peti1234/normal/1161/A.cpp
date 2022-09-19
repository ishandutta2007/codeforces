#include <bits/stdc++.h>

using namespace std;
int n, k;
bool e[100002];
bool h[100002];
bool m[100002];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        int a;
        cin >> a;
        m[a]=true;
        if (m[a-1]) {
            e[a-1]=true;
        }
        if (m[a+1]) {
            h[a+1]=true;
        }
    }
    h[1]=true;
    e[n]=true;
    int sum=0;
    for (int i=1; i<=n; i++) {
        if (!m[i]) {
            sum++;
        }
        if (!e[i]) {
            sum++;
        }
        if (!h[i]) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}