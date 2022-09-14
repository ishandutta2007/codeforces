#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=1000055;
const pair<ll,ll> mod={1000000009,988976541};
const ll inf=1e18;
ll a[N];
pair<ll,ll> pref[N];
pair<ll,ll> p[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'a'+1);
        a[i+n]=a[i];
    }
    p[0]={1,1};
    for (int i=1;i<=n*2;i++){
        p[i]={p[i-1].first*29ll%mod.first,p[i-1].second*29ll%mod.second};
    }
    pref[0]={0,0};
    for (int i=1;i<=n*2;i++){
        pref[i].first=(pref[i-1].first+p[i].first*a[i])%mod.first;
        pref[i].second=(pref[i-1].second+p[i].second*a[i])%mod.second;
    }
    int ind=n;
    for (int i=2;i<=n;i++){
        bool better=false;
        int len=0;
        for (int j=20;j>=0;j--){
            if (len+(1<<j)>n) continue;
//            if (j==0 && len==0) cout<<(pref[i+len+(1<<j)-1].first-pref[i-1].first+mod.first)%mod.first<<" "<<(pref[len+(1<<j)].first*p[i-1].first)%mod.first<<endl;
            if ((pref[i+len+(1<<j)-1].first-pref[i-1].first+mod.first)%mod.first==(pref[len+(1<<j)].first*p[i-1].first)%mod.first){
                if ((pref[i+len+(1<<j)-1].second-pref[i-1].second+mod.second)%mod.second==(pref[len+(1<<j)].second*p[i-1].second)%mod.second){
                    len+=(1<<j);
                }
            }
        }
//        cout<<"AAA "<<len<<endl;
        if (a[len+1]<a[i+len]) {
            ind=i-1;
            break;
        }
    }
    string s="";
    for (int i=1;i<=ind;i++){
        s+=char('a'+a[i]-1);
    }
    while (s.size()<k) s=s+s;
    while (s.size()>k) s.pop_back();
    cout<<s<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
    int n;cin>>n;
    if (n&(n-1)){
        if (n%2){
            cout<<"Bob\n";
        } else {
            cout<<"Alice\n";
        }
        return;
    }
    int k=0;
    while ((1<<k)<n) k++;
    if (k==0 || k%2){
        cout<<"Bob\n";
    } else {
        cout<<"Alice\n";
    }
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2