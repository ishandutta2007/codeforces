#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll res = n/2;
        for(int i = 0 ; i + 1 < n; i ++ ){
            if(a[i] < a[i + 1]){
                res = max(res, (i + 1) * 1ll * (n - i - 1));
            }
        }
        cout << res << "\n";
    }
    return 0;
}