//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
const int N=1000010;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    int k;cin>>k;
    for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int x=(k+n+1)/2;
    int mn=1000000001;
    for (int i=x;i<=n;i++){
        mn=min(mn,b[i]-b[i-x+1]);
    }
    int L,R;
    for (int i=x;i<=n;i++){
        if (b[i]-b[i-x+1]==mn){
            L=b[i-x+1];
            R=b[i];
        }
    }

    vector<int>r={0};
    int sum=0;
    int cnt=1;
    for (int i=1;i<=n && cnt<k;i++){
        if (a[i]>=L && a[i]<=R) sum++;
        else sum--;
        if (sum==cnt){
            r.push_back(i);
            cnt++;
//            if (cnt==k) break;
        }
    }
    r.push_back(n);
    cout<<L<<" "<<R<<endl;
    for (int i=1;i<r.size();i++){
        cout<<r[i-1]+1<<" "<<r[i]<<endl;
    }
    cout<<endl;



}
int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**

**/