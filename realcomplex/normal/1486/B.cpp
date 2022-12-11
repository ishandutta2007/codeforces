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
        vector<int> xx(n), yy(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> xx[i] >> yy[i];
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        if(n % 2 == 1){
            cout << "1\n";
        }
        else{
            int xa = xx[n/2]-xx[n/2-1] + 1;
            int ya = yy[n/2]-yy[n/2-1] + 1;
            cout << (xa * 1ll * ya) << "\n";
        }
    }
    return 0;
}