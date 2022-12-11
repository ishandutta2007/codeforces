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
        ll k;
        cin >> n >> k;
        vector<ll> f(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> f[i];

        }
        sort(f.begin(), f.end());
        int p = 0;
        bool can = false;
        for(int i = 1; i < n; i ++ ){
            while(f[i] - f[p] > k) p ++ ;
            if(f[i] - f[p] == k){
                can = true;
            }
        }
        if(can)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}