#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
    fastIO;
    int q;
    cin >> q;
    for(int i = 0 ; i < q; i ++ ){
        int n;
        cin >> n;
        int a[n];
        for(int j = 0 ; j < n; j ++ ){
            cin >> a[j];
        }
        bool o1 = true, o2 = true;
        int p;
        int l;
        for(int j = 0 ; j < n; j ++ ){
            if(a[j] != 1) continue;
            p = j;
            for(int t = 1; t < n; t ++ ){
                l = p;
                p = (p - 1 + n) % n;
                if(a[p] != a[l] + 1){
                    o1 = false;
                }
            }
            p = j;
            for(int t = 1; t < n; t ++ ){
                l = p;
                p = (p + 1 + n) % n;
                if(a[p] != a[l] + 1){
                    o2 = false;
                }
            }
        }
        if(o1 || o2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}