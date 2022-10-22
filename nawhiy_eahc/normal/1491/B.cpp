#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; ll u, v;
        cin >> n >> u >> v;
        for(int i=1;i<=n;i++) cin >> a[i];
        bool ok = true, ok2 = true;
        for(int i=2;i<=n;i++){
            if(a[i] != a[1]) ok = false;
            if(abs(a[i] - a[i-1]) > 1) ok2 = false;
        }

        if(ok) cout << min(2*v, u+v) << "\n";
        else if(!ok2) cout << "0\n";
        else cout << min(u, v) << "\n";
    }
}