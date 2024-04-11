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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
string pi(int n){
    string s="";
    while (n){
        int r = n%10;
        n/=10;
        s = char('0'+r)+s;
    }
    return s;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        stack<pair<string,int>> st;
        cin >> n;
        rep(i,0,n){
            int v;
            cin >> v;
            if (!i){
                cout << v << endl;
                st.push({"",1});
                continue;
            }
            if (v == 1){
                cout << st.top().X << st.top().Y << '.' << 1 << endl;
                string s = st.top().X;
                s += pi(st.top().Y);
                s += '.';
                st.push({s,1});
                continue;
            }
            while (v != st.top().Y+1) st.pop();
            cout << st.top().X << v << endl;
            string s = st.top().X;
            st.pop();
            st.push({s,v});
        }
    }
    return 0;
}