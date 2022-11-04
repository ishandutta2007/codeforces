#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[2001];
int b[2001];

bool ok[2000001];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        ok[a[i]] = 1;
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
        ok[b[i]] = 1;
    }
    int ans = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
           if((a[i] ^ b[j]) <= 2e6 && ok[a[i] ^ b[j]] == 1)
              ans++;
    if(ans % 2 == 0)
        cout << "Karen";
    else
        cout << "Koyomi";
    //cin.close();
    //cout.close();
    return 0;
}