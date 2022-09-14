#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[200001];
int32_t main() {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=n;
    for (int i=1;i<=n;i++){
        set<int>st;
        for (int j=1;j<i;j++) st.insert(a[j]);
        if (st.size()==i-1) res=min(res,n-i+1);
        for (int j=n;j>=i;j--){
            st.insert(a[j]);

            if (st.size()==n-j+i) res=min(res,j-i);
        }
    }
    cout<<res;
    return 0;
}


///2007521364118