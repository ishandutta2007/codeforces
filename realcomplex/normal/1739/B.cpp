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
        vector<int> d(n);
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ) cin >> d[i];
        a[0] = d[0];
        bool valid = true;
        for(int i = 1; i < n;i ++ ){
            a[i] = a[i - 1] + d[i];
            if(a[i - 1] - d[i] >= 0 && d[i] > 0){
                cout << "-1";
                valid = false;
                break;
            }
        }
        if(valid)
            for(auto x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}