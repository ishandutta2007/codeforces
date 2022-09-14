//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int n,k;
int f(int x){
    return (x-1)/(k+1)+1;
}
void solve(){
    cin>>n>>k;
    string s;cin>>s;
    vector<int>v={-1-k};
    for (int i=0;i<s.size();i++){
        if (s[i]=='1') v.push_back(i);
    }
    v.push_back(n+k);
    int res=0;
    for (int i=1;i<v.size();i++){
        if (v[i]-k-1>=v[i-1]+k+1) res+=f(v[i]-k-1-v[i-1]-k-1+1);
    }
    cout<<res<<endl;
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