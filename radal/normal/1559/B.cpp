#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=8e18;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,l=-1;
        string s;
        cin >> n;
        cin >> s;
        rep(i,0,n){
            if (s[i] != '?'){
                l = i;
                break;
            }
        }
        if (l == -1){
            rep(i,0,n){
                if (i&1) cout << 'B';
                else cout << 'R';
            }
            cout << endl;
            continue;
        }
        repr(i,l-1,0){
            if (s[i+1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
        rep(i,l+1,n){
            if (s[i] == '?'){
                if (s[i-1] == 'R') s[i] = 'B';
                else s[i] = 'R';
            }
        }
        cout << s << endl;
    }
    return 0;
}