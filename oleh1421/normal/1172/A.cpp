//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
int a[N];
int b[N];
int pos[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i],pos[b[i]]=i;
    bool ok=true;
    for (int i=pos[1];i<=n;i++){
        if (b[i]!=i-pos[1]+1) ok=false;
    }
    if (ok){
        for (int i=1;i<pos[1];i++){
            if (b[i]==0) continue;
            if (i>=b[i]-(n-pos[1]+1)) ok=false;
        }
    }
    if (ok){
        cout<<pos[1]-1<<endl;
        return 0;
    }
    int maxx=-1;
    for (int i=1;i<=n;i++){
        maxx=max(maxx,pos[i]-i);
    }
    cout<<n+maxx+1<<endl;
    return 0;
}

/*
7 5
4 5 6 1 2 3 7
1 3
1 2
2 2
3 4
6 6
*/