//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
string s[N];
int n,m;
bool ok(string res){
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<m;j++){
            cnt+=(s[i][j]!=res[j]);
        }
        if (cnt>1) return false;
    }
    return true;
}
void solve(){
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>s[i];
    string res=s[0];
    for (int i=0;i<m;i++){
        for (int j=0;j<26;j++){
            res[i]=char(j+'a');
            if (ok(res)){
                cout<<res<<endl;
                return;
            }
        }
        res[i]=s[0][i];
    }
    cout<<-1<<endl;
//    int n;cin>>n;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            char c;cin>>c;
//            a[i][j]=(c-'0');
//        }
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4 3
000
111
100
011
*/