#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000100;
bool is_substr(ll x,ll y){
    vector<int>u,v;
    while (x){
        u.push_back(x%2);
        x/=2;
    }
    while (y){
        v.push_back(y%2);
        y/=2;
    }
    for (int i=0;i<=(int)v.size()-(int)u.size();i++){
        bool ok=true;
        for (int j=0;j<u.size();j++){
            ok&=(u[j]==v[i+j]);
        }
        for (int j=0;j<i;j++) ok&=v[j];
        for (int j=i+(int)u.size();j<v.size();j++) ok&=v[j];
        if (ok) return true;
    }
    reverse(v.begin(),v.end());
    for (int i=0;i<=(int)v.size()-(int)u.size();i++){
        bool ok=true;
        for (int j=0;j<u.size();j++){
            ok&=(u[j]==v[i+j]);
        }
        for (int j=0;j<i;j++) ok&=v[j];
        for (int j=i+(int)u.size();j<v.size();j++) ok&=v[j];
        if (ok) return true;
    }
    return false;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x,y;cin>>x>>y;

    if (x==y){
        cout<<"YES\n";
        return 0;
    }
    if (is_substr(x*2ll+1,y)){
        cout<<"YES\n";
        return 0;
    }
    while (x%2==0) x/=2;
    if (is_substr(x,y)){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";

    return 0;

}
/**
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/