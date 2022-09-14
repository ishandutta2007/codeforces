#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
const int N=300010;
#define endl '\n'
void solve(){
    string s;cin>>s;
    int d=(s[0]-'0');
    int res=0;
    for (int i=1;i<d;i++){
        for (int j=1;j<=4;j++){
            res+=j;
        }
    }
    for (int i=1;i<=s.size();i++) res+=i;
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}