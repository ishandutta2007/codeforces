#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

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
        ll rem = 0;
        ll x;
        bool valid = true;
        for(int i = 0; i < n; i ++ ){
            cin >> x;
            rem += x;
            if(rem >= i){
                rem -= i;
            }
            else{
                valid=false;
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}