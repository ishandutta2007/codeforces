#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100046];
map<int,int>used;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    bool ok=true;
    int cnt=0;
    set<int>st;
    for (int i=0;i<n;i++){
        used[a[i]]++;
        st.insert(a[i]);
        if (used[a[i]]>2 || (a[i]==0 && used[0]==2) || (used[a[i]-1] && used[a[i]]>1)) ok=false;
    }
    for (auto i:st){
        if (used[i]>=2) cnt++;
    }
    if (cnt>1) ok=false;
    if (!ok){
        cout<<"cslnb";
        return 0;
    }
    ll sum=0;
    ll xr=0;
    for (int i=0;i<n;i++){
        a[i]-=i;
    if (a[i]<0){
        cout<<"cslnb";
        return 0;
    }
        sum+=a[i]*1ll;
        xr^=a[i]*1ll;
    }
    sum%=2ll;
    if (sum) cout<<"sjfnb";
    else cout<<"cslnb";

    return 0;
}
//2 6 -2 -6  2