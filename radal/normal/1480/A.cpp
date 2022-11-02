#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> s;
        n = s.size();
        rep(i,0,n){
            if (i%2){
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
            else{
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout << s << endl;
    }
    return 0;
}