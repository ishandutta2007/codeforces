#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
int cnt[30];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<26;i++) cnt[i]=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        cnt[c-'a']++;
    }
    int rem=0;
    for (int i=0;i<26;i++){
        rem+=cnt[i]%2;
    }
    int sum=(n-rem)/2;
    int res=0;
    for (int i=0;i<=sum;i++){
        if (i%k+(n-i*2)>=k) res=max(res,(i/k)*2+1);
        else res=max(res,(i/k)*2);
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

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/