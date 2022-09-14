//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
int a[N];
int p[N];
bool used[N];
bool in[N];
bool take[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],used[i]=false,in[i]=false,take[i]=false,ans[i]=0,p[i]=0;
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (!used[a[i]]){
            v.push_back(i);
            take[i]=true;
            used[a[i]]=true;
        }
    }
    if (v.size()==n){
        cout<<n<<endl;
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    if (v.size()==n-1){
        int x=-1;
        for (int i=1;i<=n;i++){
            if (!used[i]) x=i;
        }
        for (int i=1;i<=n;i++) used[i]=false,in[i]=false,take[i]=false,ans[i]=0,p[i]=0;
        v.clear();
        used[a[x]]=true;
        take[x]=true;
        v.push_back(x);
        for (int i=1;i<=n;i++){
            if (i==x) continue;
            if (!used[a[i]]){
                v.push_back(i);
                take[i]=true;
                used[a[i]]=true;
            }
        }
    }
    for (int i:v) in[a[i]]=true,p[a[i]]=i,ans[i]=a[i];
    vector<int>x,y;
    for (int i=1;i<=n;i++){
        if (take[i]) continue;
        if (in[i]) x.push_back(i);
        else y.push_back(i);
    }
    if (x.empty()){
        for (int i=0;i<y.size();i++){
            ans[y[i]]=y[(i+1)%y.size()];
        }
    } else {
        int last=x.back();
        for (int i:y){
            ans[last]=i;
            last=i;
        }
        int cur=x.back();
        while (p[cur]) cur=p[cur];
        ans[last]=cur;
        x.pop_back();
        for (int i:x){
            int cur=i;
            while (p[cur]) cur=p[cur];
            ans[i]=cur;
        }
    }
    cout<<v.size()<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
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
5
6 9 1 9 6
**/