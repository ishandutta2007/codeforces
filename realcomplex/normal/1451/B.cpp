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
    for(int t = 1; t <= tc; t ++ ){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        char f;
        for(int i = 0 ; i < n; i ++ ){
            cin >> f;
            a[i] = f - '0';
        }
        int l, r;
        for(int i = 0; i  < q; i ++ ){
            cin >> l >> r;
            l--;
            r--;
            bool answ = false;
            for(int j = l - 1; j >= 0; j  -- ){
                if(a[j] == a[l]) answ = true;
            }
            for(int j = r + 1; j < n; j ++ ){
                if(a[j] == a[r]) answ = true;
            }
            if(answ)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}