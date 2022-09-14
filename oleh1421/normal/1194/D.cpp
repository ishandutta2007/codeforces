#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
bool dp[100001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,k;cin>>n>>k;
        if (k%3){
            if (n%3) cout<<"Alice\n";
            else cout<<"Bob\n";
        } else {
            n%=k+1;
            if (n%3 || n>k-3) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }

    return 0;
}
//2 6 -2 -6  2