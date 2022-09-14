//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
int x[3],y[3];
void solve(){
    string s;cin>>s;
    while (!s.empty()){
        char c=(int)s.size()-1+'a';
        if (s.back()==c) s.pop_back();
        else if (s[0]==c){
            string t="";
            for (int j=1;j<s.size();j++) t+=s[j];
            s=t;
        } else {
            cout<<"NO\n";
            return;
        }

    }
    cout<<"YES\n";

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 4
1 2
2 3
1 4
4 3
**/