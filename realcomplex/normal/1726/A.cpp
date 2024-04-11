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
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> a(n);
        int res = -(int)1e9;
        int l1 = 0;
        int r1 = (int)1e9;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        for(int i = 0 ; i < n; i ++ ){
            if(i < n)
                res = max(res, a[n - 1] - a[i]);
            if(i > 0)
                res = max(res, a[i] - a[0]);
            res = max(res, a[i] - a[(i + 1) % n]);
        }
        cout << res << "\n";
    }
    return 0;
}