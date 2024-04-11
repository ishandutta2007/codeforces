#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll a[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        map<ll, int> m;

        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            if(m[a[i]-k]) flag = true;
            if(m[a[i]+k]) flag = true;
            m[a[i]] = 1;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}