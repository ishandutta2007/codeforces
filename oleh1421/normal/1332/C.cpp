//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int cnt[N][26];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<=k;i++){
        for (int j=0;j<26;j++){
            cnt[i][j]=0;
        }
    }
    for (int i=0;i<n;i++){
        char c;cin>>c;
        int pos=min(i%k,k-i%k-1);
        cnt[pos][c-'a']++;
    }
    int res=0;
    for (int i=0;i<k;i++){
        int sum=0;
        int maxx=0;
        for (int j=0;j<26;j++){
            sum+=cnt[i][j];
            maxx=max(maxx,cnt[i][j]);
        }
        sum-=maxx;
        res+=sum;
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
/*
2
4
2 -2
2 2
-2 2
-2 -2
1
0 2 10
4
1 -1
1 1
-1 1
-1 -1
2
0 1 10
1 1 10
*/