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
        string s;
        cin >> s;
        int x = 0;
        int y = 0;
        ll res = 0;
        for(char p : s){
            if(p == '0'){
                x ++ ;
            }
            else{
                y ++ ;
            }
        }
        if(x > 0 && y > 0){
            res = x * 1ll * y;
        }
        int len = 0;
        for(char p : s){
            if(p == '0'){
                len++;
                res = max(res, len * 1ll * len);
            }
            else{
                len=0;
            }
        }
        len = 0;
        for(char p : s){
            if(p == '1'){
                len++;
                res = max(res, len * 1ll * len);
            }
            else{
                len=0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}