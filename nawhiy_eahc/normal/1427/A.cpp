#include <bits/stdc++.h>

using namespace std;
int a[52];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += a[i];
        }

        if(sum == 0)cout << "NO\n";
        else if(sum > 0){
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                if(a[i] > 0) cout << a[i] << " ";
            }
            for(int i=1;i<=n;i++){
                if(a[i] == 0) cout << a[i] << " ";
            }
            for(int i=1;i<=n;i++){
                if(a[i] < 0) cout << a[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                if(a[i] < 0) cout << a[i] << " ";
            }
            for(int i=1;i<=n;i++){
                if(a[i] == 0) cout << a[i] << " ";
            }
            for(int i=1;i<=n;i++){
                if(a[i] > 0) cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}