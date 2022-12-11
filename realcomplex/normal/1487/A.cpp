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
        int n;
        cin >> n;
        int low = 105;
        vector<int> a(n);
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
            low = min(low, a[i]);
        }
        int outp = 0;
        for(auto x : a)
            if(x != low) outp ++ ;
        cout << outp << "\n";
    }
    return 0;
}