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
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        int low = a[0];
        bool sol = true;
        for(int i = 1; i < n; i ++ ){
            low = min(low, a[i]-a[i-1]+low);
            low = min(low, a[i]);
            if(low < 0){
                sol = false;
                break;
            }
        }
        if(sol){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}