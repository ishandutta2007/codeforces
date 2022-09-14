#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll mod=1000000007;
const ll inf=4e18;
const int L=20;
int val[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    a[0]=0;
    int res=0;
    for (int i=2;i<n;i++){
        if (a[i]>a[i-1] && a[i]>a[i+1]){
            a[i+1]=max(a[i],a[i+2]);
            res++;
        }
    }
    cout<<res<<endl;
//    vector<int>v;
//    for (int i=1;i<=n;i++){
//        while (!v.empty() && v.back()<a[i]) v.pop_back();
//        v.push_back(a[i]);
//        val[i]+=i-v.size();
//    }
//    v.clear();
//    reverse(a+1,a+n+1);
//    for (int i=1;i<=n;i++){
//        while (!v.empty() && v.back()<a[i]) v.pop_back();
//        v.push_back(a[i]);
//        val[n-i+1]+=i-v.size();
//    }
//    v.clear();
//    reverse(a+1,a+n+1);
//    int best=1;
//    for (int i=2;i<=n;i++){
//        if (val[best]>val[i]) best=i;
//    }
//    for (int i=best+1;i<=n;i++) a[i]=max(a[i],a[i-1]);
//    for (int i=best-1;i>=1;i--) a[i]=max(a[i],a[i+1]);
//    cout<<val[best]<<endl;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

}
int32_t main()
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
12837720
**/