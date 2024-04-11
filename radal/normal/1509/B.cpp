#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,t1=0,t2=0;
        string s;
        cin >> n >> s;
        bool f = 1;
        rep(i,0,n){
            if (s[i] == 'T') t1++;
            else t2++;
            if (t2 > t1) f = 0;
        }
        if (t1 != 2*t2 || !f){
            cout << "NO" << endl;
            continue;
        }
        t1 = 0;
        t2 = 0;
        f = 1;
        repr(i,n-1,0){
            if (s[i] == 'T') t1++;
            else t2++;
            if (t1 < t2) f = 0;
        }
        cout << ((f) ? "YES" : "NO") << endl;
    }
    return 0;
}