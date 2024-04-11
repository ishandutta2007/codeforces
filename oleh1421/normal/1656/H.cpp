#include <bits/stdc++.h>
//typedef long long ll;
typedef __int128_t ll;
#define endl '\n'
using namespace std;
const int N=1010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
ll a[N];
ll b[N];
ll G[N][N];
bool usedA[N],usedB[N];
void print(ll x){
    vector<int>v;
    while (x){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(),v.end());
    for (int i:v) cout<<i;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        a[i]=0;
        string s;cin>>s;
        for (auto j:s){
            a[i]*=10ll;
            a[i]+=j-'0';
        }
        usedA[i]=false;
    }

    for (int i=1;i<=m;i++){
        b[i]=0;
        string s;cin>>s;
        for (auto j:s){
            b[i]*=10ll;
            b[i]+=j-'0';
        }
        usedB[i]=false;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    sort(b+1,b+m+1);
    reverse(b+1,b+m+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            G[i][j]=__gcd(a[i],b[j]);
        }
    }
    int haveA=n,haveB=m;
    vector<int>goodA,goodB;
    for (int i=1;i<=n;i++){
        goodA.push_back(i);
    }
    for (int i=1;i<=m;i++){
        goodB.push_back(i);
    }
    while (haveA>0 && haveB>0){
        bool was=false;
        vector<int>nwA;
        for (int i:goodA){
            ll lcm=1ll;
            for (int j:goodB){
                ll g=G[i][j];
                if (lcm%g==0) continue;
                ll g1=__gcd(g,lcm);
                lcm*=g/g1;
                if (lcm==a[i]) break;
            }
            if (lcm!=a[i]) {
                usedA[i]=true;
                haveA--;
                was=true;
            } else nwA.push_back(i);
        }
        goodA=nwA;
        vector<int>nwB;
        for (int i:goodB){
            ll lcm=1;
            for (int j:goodA){
                ll g=G[j][i];
                if (lcm%g==0) continue;
                ll g1=__gcd(lcm,g);
                lcm*=g/g1;
                if (lcm==b[i]) break;
            }
            if (lcm!=b[i]) {
                usedB[i]=true;
                haveB--;
                was=true;
            } else nwB.push_back(i);
        }
        goodB=nwB;
        if (was) continue;
        cout<<"YES\n";
        cout<<haveA<<" "<<haveB<<endl;
        for (int i=1;i<=n;i++){
            if (!usedA[i]) {
                print(a[i]);
                cout<<" ";
            }
        }
        cout<<endl;
        for (int i=1;i<=m;i++){
            if (!usedB[i]){
                print(b[i]);
                cout<<" ";
            }
        }
        cout<<endl;
        return;
    }
    cout<<"NO\n";

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


//2
//
//1 2

/**
3
3 -1 -2


**/