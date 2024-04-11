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
    for(int tt = 0 ; tt < q; tt ++ ){
        int n;
        cin >> n;
        vector<int> li;
        int a;
        for(int i = 0 ; i < n * 4; i ++ ){
            cin >> a;
            li.push_back(a);
        }
        sort(li.begin(), li.end());
        vector<int> zz;
        for(int i = 1; i < li.size(); i += 2 ){
            if(li[i] == li[i - 1])
                zz.push_back(li[i]);
        }
        bool ok = true;
        int m = 2 * n;
        if(zz.size() != m)
            ok = false;
        int has = zz[0] * zz[m - 1];
        if(ok){
            for(int i = 0 ; i < m; i ++ ){
                if(zz[i] * zz[m - i - 1] != has) ok = false;
            }
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}