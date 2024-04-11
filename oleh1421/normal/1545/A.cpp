//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int a[N];
//int t[N];
//void upd(int n,int pos,int x){
//    for (;pos<=n;pos|=pos+1) t[pos]+=x;
//}
//int get(int pos){
//    int sum=0;
//    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
//    return sum;
//}
int ind[N];
map<int,int>mp[2];

void solve(){
    mp[0].clear();
    mp[1].clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        mp[i%2][a[i]]++;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        mp[i%2][a[i]]--;
    }
    for (auto cur:mp[0]){
        if (cur.second){
            cout<<"NO\n";
            return;
        }
    }
    for (auto cur:mp[1]){
        if (cur.second){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
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
4 4
1 2
2 3
1 4
4 3
**/