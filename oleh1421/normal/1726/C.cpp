//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
//#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
int a[N];
int pref[N];
int nxt[N];
int ans=0;
void rec(int l,int r){
    if (l>r) return;
    ans++;
    while (l<=r){
        rec(l+1,nxt[l]-1);
        l=nxt[l]+1;
    }
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    n*=2;
    for (int i=0;i<n;i++){
        a[i+1]=(s[i]=='(')*2-1;
    }
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    vector<int>st;
    for (int i=1;i<=n;i++){
        if (a[i]==1) st.push_back(i);
        else {
            nxt[st.back()]=i;
            st.pop_back();
        }
    }

    ans=0;
    rec(1,n);
    cout<<ans<<'\n';

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
9
1 2 1
1 3 1
1 4 1
1 5 1
2 6 1
3 7 1
4 8 1
5 9 1
*/