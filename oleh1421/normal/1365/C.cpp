//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500010;
int a[N];
int b[N];
int pos[N];
int cnt[N];
void solve()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        cnt[(i-pos[b[i]]+n)%n]++;
    }
    int mx=0;
    for (int i=0;i<n;i++) mx=max(mx,cnt[i]);
    cout<<mx<<endl;

}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}