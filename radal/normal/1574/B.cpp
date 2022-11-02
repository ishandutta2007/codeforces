#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5,mod = 1e9+7;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int a,b,c,m;
        cin >> a >> b >> c >> m;
        if (m > a+b+c-3){
            cout << "NO" << endl;
            continue;
        }
        if (a < b) swap(a,b);
        if (a < c) swap(a,c);
        if (b < c) swap(b,c);
        if (b+c+1 >= a){
            cout << "YES" << endl;
            continue;
        }
        if (m >= a-b-c-1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}