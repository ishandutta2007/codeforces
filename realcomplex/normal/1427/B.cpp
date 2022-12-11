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
        int n, k;
        cin >> n >> k;
        int zero = 0;
        int one = 0;
        char x;
        int las = -1;
        vector<int> c;
        int segs = 0;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            if(x == 'L') {
                zero ++ ;
                continue;
            }
            one ++ ;
            if(las != i - 1 && las != -1){
                c.push_back(i-las-1);
                segs ++ ;
            }
            las = i;
        }
        one += min(zero, k);
        if(one) segs ++ ;
        int sol = 2 * one - segs;

        sort(c.begin(), c.end());
        for(auto x : c){
            if(k - x >= 0){
                k -= x;
                sol ++ ;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}