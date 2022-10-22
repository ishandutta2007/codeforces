#include <bits/stdc++.h>

using namespace std;
int a[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == a[1]) cnt++;
        }

        cout << n - cnt << "\n";
    }
}