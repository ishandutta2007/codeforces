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
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int soln = (int)2e9;
        for(int i = 0 ; i + 2 < n; i ++ ){
            soln = min(soln, a[i + 2] - a[i]);
        }
        cout << soln << "\n";
    }
    return 0;
}