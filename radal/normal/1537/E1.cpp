#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
bool sm(string s,string t){
    int p = 0,n=s.size(),m=t.size();
    while(s.size() < m){
        s += s[p];
        p++;
        p %= n;
    }
    n = s.size();
    p = 0;
    while (t.size() < n){
        t += t[p];
        p++;
        p %= m;
    }
    m = t.size();
    rep(i,0,n){
        if (int(s[i]) < int(t[i])) return 1;
        if (int(s[i]) > int(t[i])) return 0;
    }
    return 0;
}
int main(){
 //   ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    while (T--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        repr(i,n-1,1) if (s[i] > s[0]) n=i+1;
        int p = 0;
        string t = "",w="";
        w += s[0];
        t += s[0];
        rep(i,1,n){
            w+=s[i];
            if (sm(w,t)){
                t = w;
                p = i;
            }
        }
        p++;
        while (k > p){
            cout << t;
            k -= p;
        }
        int u = 0;
        while (k){
            cout << t[u];
            k--;
            u++;
        }
        cout << endl;
    }
}