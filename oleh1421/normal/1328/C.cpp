//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
int b[N];
int r[N];
map<int,int>cnt;
ll pref[N];
ll suf[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string a="",b="";
    bool ok=false;
    for (auto i:s){
        if (!ok){
            if (i=='2'){
                a+='1';
                b+='1';
            } else if (i=='0'){
                a+='0';
                b+='0';
            } else {
                a+='1';
                b+='0';
                ok=true;
            }
        } else {
            a+='0';
            b+=i;
        }
    }
    cout<<a<<endl<<b<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
//x 0 1 2
//0 0 1 2
//1 1 2 0
//2 2 0 1