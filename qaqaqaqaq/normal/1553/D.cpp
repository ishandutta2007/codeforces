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

const int maxn=300007;


int _;
string s,t;
signed main(){
    cin>>_;
    while (_--){
        cin>>s>>t;
        reverse(range(s)), reverse(range(t));
        bool ok=0;
        int j=0;
        rep(i,sz(s)){
            if (s[i]==t[j]) j++;
            else i++;
            if (j==sz(t)) {ok=1; break;}
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}