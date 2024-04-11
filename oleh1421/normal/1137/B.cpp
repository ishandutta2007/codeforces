//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=1e18;
const ll mod=998244353;

void solve(int Case){
    string s;cin>>s;
    string t;cin>>t;
    int n=t.size();
    int mx=0;
    ll A=0ll;
    ll B=0ll;
    ll pw=1ll;
    vector<int>v;
    for (int i=n-1;i>=1;i--){
        A*=2ll;
        A+=t[i]-'0';
        A%=mod;
        B+=pw*(t[n-i-1]-'0');
        B%=mod;
        pw*=2ll;
        pw%=mod;
//        cout<<A<<" "<<B<<endl;
        if (A==B){
            v.push_back(n-i);
        }
    }
    reverse(v.begin(),v.end());
    for (int i:v){
        bool ok=true;
        for (int j=0;j<i;j++){
            ok&=(t[j]==t[n-i+j]);
//            if (!ok){
//                cout<<j<<" "<<t[j]<<" "<<t[n-i+j]<<endl;
//            }
        }
        if (ok){
            mx=i;
            break;
        }
    }
//    cout<<"A "<<mx<<endl;
    int z=0,o=0;
    for (auto i:s){
        if (i=='0') z++;
        else o++;
    }
    int stz=0,sto=0;
    for (auto i:t){
        if (i=='0') stz++;
        else sto++;
    }
    if (stz>z || sto>o){
        cout<<s<<endl;
        return;
    }
    string ans=t;
    z-=stz;
    o-=sto;
    string add="";
    for (int i=mx;i<n;i++){
        add+=t[i];
    }
    int addz=0,addo=0;
    for (auto i:add){
        if (i=='0') addz++;
        else addo++;
    }
//    cout<<addz<<" "<<addo<<endl;
    while (addz<=z && addo<=o){
        z-=addz;
        o-=addo;
        ans+=add;
    }
    for (int i=0;i<z;i++) ans+='0';
    for (int i=0;i<o;i++) ans+='1';
    cout<<ans<<endl;




}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
1111111100000
11010110

problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/