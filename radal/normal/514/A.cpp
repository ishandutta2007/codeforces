#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e5+30,inf = 1e9;
int main(){
    string s;
    cin >> s;
    int sz = s.size();
    rep(i,1,sz){
        if (int(s[i])-int('0') > 4) s[i] = char(int('9')-int(s[i])+int('0'));
    }
    if (s[0] != '9' && int(s[0])-int('0') > 4){
        s[0] = char(int('9')-int(s[0])+int('0'));
    }
    cout << s << endl;
    return 0;
}