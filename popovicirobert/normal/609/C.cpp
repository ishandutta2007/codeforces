#include <bits/stdc++.h>
#define ll long long
#define MAXN 100000


using namespace std;

int a[MAXN + 1], b[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(i = 1; i <= n; i++) {
        b[i] = sum / n;
        if(i <= sum % n)
            b[i]++;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    long long ans = 0;
    for(i = 1; i <= n; i++)
        ans += abs(a[i] - b[i]);
    cout << ans / 2;
    //cin.close();
    //cout.close();
    return 0;
}