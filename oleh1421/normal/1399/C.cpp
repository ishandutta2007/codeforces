#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1501050;
int a[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n*2;i++) cnt[i]=0;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    int res=0;
    for (int s=2;s<=n*2;s++){
        int cur=0;
        for (int i=1;i*2<s;i++) cur+=min(cnt[i],cnt[s-i]);
        if (s%2==0) cur+=cnt[s/2]/2;
        res=max(res,cur);
    }
    cout<<res<<endl;
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
1
7 1 2 1
1110010


1
6 1 2 1
011110
**/