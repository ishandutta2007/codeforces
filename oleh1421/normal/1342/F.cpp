#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=20;
bool solved=true;
vector<int>x;
vector<int>y;
int a[N];
int used[N];
int sum[N];
int total=0;
void F(int pos,int last){
    if (solved) return;
    if (pos==x.size()){
        solved=true;
        cout<<y.size()<<endl;
        for (int i=0;i<y.size();i++){
            if (!used[i]) used[i]=x.size();
            int cnt=0;
            for (int j=0;j<i;j++) cnt+=(y[j]<x[used[i]-1]);
            cout<<y[i]+1-i<<" "<<x[used[i]-1]+1-cnt<<endl;
        }
        return;
    }
    int need=0;
    for (int i=pos+1;i<x.size();i++){
        need+=max(0,sum[pos]-sum[i]);
    }
    if (need>total) return;

    if (pos==0 || sum[pos]>sum[pos-1]){
        F(pos+1,-1);
        return;
    }

    for (int i=last+1;i<y.size();i++){
        if (used[i]) continue;
        sum[pos]+=a[y[i]];
        total-=a[y[i]];
        used[i]=pos+1;
        F(pos,i);
        used[i]=0;
        total+=a[y[i]];
        sum[pos]-=a[y[i]];
    }
}
void solve(){
    solved=false;
    vector<pair<int,int> >v;
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int mask=0;mask<(1<<n);mask++){
        v.push_back({__builtin_popcount(mask),mask});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (auto cur:v){
        x.clear();
        y.clear();
        for (int i=0;i<n;i++){
            if (cur.second&(1<<i)) x.push_back(i);
            else y.push_back(i);
        }
        memset(used,0,sizeof(used));
        for (int i=0;i<x.size();i++) sum[i]=a[x[i]];
        total=0;
        for (auto i:y) total+=a[i];
        F(1,-1);
        if (solved) break;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
 
    return 0;
}