//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
const ll mod=1000000007;
int n,m;
int ask(vector<int>v){
    string s="";
    for (int i=0;i<m;i++) s+="0";
    for (int i:v) s[i]='1';
    cout<<"? "<<s<<endl;
    int ans;cin>>ans;
    return ans;
}
void solve(int Case){
    cin>>n>>m;
    vector<pair<int,int> >v;
    for (int i=0;i<m;i++){
        v.push_back({ask({i}),i});
    }
    sort(v.begin(),v.end());
    vector<int>take;
    int sum=0;
    for (auto cur:v){
        take.push_back(cur.second);
        if (sum+cur.first==ask(take)){
            sum+=cur.first;
        } else {
            take.pop_back();
        }
    }
    cout<<"! "<<sum<<endl;


}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/