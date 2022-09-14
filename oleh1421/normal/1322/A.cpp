//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=1000000007ll;
const int N=1000010;
int s[N];
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='(') s[i]=s[i-1]+1;
        else s[i]=s[i-1]-1;
    }
    if (s[n]!=0){
        cout<<-1;
        return 0;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (s[i]>=0) continue;
        int j=i;
        while (s[j]<0) j++;
        res+=j-i+1;
        i=j;
    }
    cout<<res;
    return 0;
}