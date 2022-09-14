//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;
int a[N],b[N];
void solve(int Case){
    int n,k;cin>>n>>k;

    map<int,int>mp;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    if (k>=n){
        cout<<0<<endl;
        return;
    }
    int m=0;
    for (auto cur:mp){
        m++;
        a[m]=cur.first;
        b[m]=cur.second;
    }
    a[0]=0;
    a[m+1]=1000000001;
    b[m+1]=0;
    int res=1000000001;
    int sum=0;
    multiset<int>st;
    int tot=0;
    int L=0;
    for (int i=1;i<=m;i++) L+=b[i];
    for (int i=m+1;i>=1;i--){
        if (i<=m){
            if (sum+b[i]<=k){
                st.insert(b[i]);
                sum+=b[i];
            } else if (!st.empty() && b[i]<(*st.rbegin())){
                sum-=(*st.rbegin());
                st.erase(--st.end());
                sum+=b[i];
                st.insert(b[i]);
            }
            tot+=b[i];
            L-=b[i];
        }

        int cur=(m-i+1)-(int)st.size();
        if (L+tot>=a[i-1]+1 && k>=a[i-1]+1-(i-1)){
            res=min(res,cur);
        }
    }
    res=min(res,m-(int)st.size());
    for (int i=1;i<=m;i++){
        if (a[i]==i-1) res=min(res,m-i);
    }

    cout<<res<<endl;
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
9 10 0 8
0 1
1 2
2 3
3 4
1 4
4 5
7 5
6 7
0 6
7 8



**/