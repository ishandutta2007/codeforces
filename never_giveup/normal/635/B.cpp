#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e6;

int n, a[maxn], b[maxn];

int main()
{
    cin >> n;
    int j = 0;
    for (int i = 0; i < n; i++){
        cin >> a[j];
        if (a[j] > 0)
            j++;
    }
    j = 0;
    for (int i = 0; i < n; i++){
        cin >> b[j];
        if (b[j] > 0)
            j++;
    }
    n--;
    for (int st = 0; st < n; st++)
        if (b[st] == a[0]){
            for (int i = st + 1; i < n; i++)
            if (b[i] != a[i - st]){
                cout << "NO";
                return 0;
            }
            for (int i = 0; i < st; i++)
            if (b[i] != a[n - st + i]){
                cout << "NO";
                return 0;
            }
            cout << "YES";
            return 0;
        }
}