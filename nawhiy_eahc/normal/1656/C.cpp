#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        bool flag = false;
        for(int i=1;i<=n;i++) if(a[i] == 1) flag = true;
        if(!flag)
        {
            cout << "YES\n";
            continue;
        }

        sort(a+1, a+n+1);
        bool f2 = false;
        for(int i=2;i<=n;i++) if(a[i] == a[i-1] + 1) f2 = true;
        if(f2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}