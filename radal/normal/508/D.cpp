#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n;
map<string,vector <int> > adj,in;
string s[N];
bool visited[6*N];
string ve = "";
set <string> st;
void dfs(string j){
    string v = "";
    v = j[1];
    v += j[2];
    while (!adj[v].empty()){
        auto u = adj[v].back();
        adj[v].pop_back();
        if (!visited[u]){
            visited[u] = 1;
            dfs(s[u]);
        }
    }
    ve += j[2];
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> s[i];
        string a = "",b = "";
        a = s[i][0];
        a += s[i][1];
        b = s[i][1];
        b += s[i][2];
        adj[a].pb(i);
        in[b].pb(i);
    }
    int cnt = 0,ind = 0,cnt1=0,cnt2=0;
    rep(i,0,n){
        string a = "";
        a = s[i][0];
        a += s[i][1];
        int sz1,sz2;
        sz1 = adj[a].size();
        sz2 = in[a].size();
        if (abs(sz1-sz2) > 1){
            cout << "NO" << endl;
            return 0;
        }
        if (st.find(a) == st.end() && sz1 > sz2){
            cnt1++;
            ind = i;
        }
        st.insert(a);
    }
    st.clear();
    rep(i,0,n){
        string b = "";
        b = s[i][1];
        b += s[i][2];
        int sz3 = adj[b].size(),sz4 =in[b].size();
        if (abs(sz3-sz4) > 1){
            cout << "NO" << endl;
            return 0;
        }
        if (st.find(b) == st.end() && sz3 < sz4) cnt2++;
        st.insert(b);
    }
    if (cnt1 != cnt2 || (cnt1 != 0 && cnt1 != 1)){
        cout << "NO" << endl;
        return 0;
    }
    visited[ind] = 1;
    dfs(s[ind]);
    ve+=s[ind][1];
    ve+=s[ind][0];
    reverse(ve.begin(),ve.end());
    rep(i,0,n){
        if (!visited[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << ve << endl;
    return 0;   
}