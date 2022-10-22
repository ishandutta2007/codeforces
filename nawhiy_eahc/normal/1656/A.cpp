#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        int b = 1, c = 1;
        for(int i=1;i<=n;i++)
        {
            if(a[b] > a[i]) b = i;
            if(a[c] < a[i]) c = i;
        }
        cout << b << " " << c << "\n";
    }
}