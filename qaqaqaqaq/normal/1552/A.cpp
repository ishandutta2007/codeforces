#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;
const int maxn=200007;
string s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        cin>>s;
        vi v,vv;
        v.clear(), vv.clear();
        for (auto c:s) v.pb(c-'a'), vv.pb(c-'a');
        sort(range(vv));
        int k=0;
        rep(i,sz(s)){
            if (v[i]==vv[i]) k++;
        }
        cout<<n-k<<"\n";
    }
    return 0;
}