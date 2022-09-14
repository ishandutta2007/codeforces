#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=201050;
int s[N];
void solve(){
    ll n,a,b,c;cin>>n>>a>>b>>c;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        s[i]=(c-'0');
    }
    bool eq=true;
    for (int i=2;i<=n;i++) eq&=(s[i]==s[i-1]);
    if (n==1){
        cout<<0<<endl;
        return;
    }
    if (eq){
        if (s[1]) cout<<b<<endl;
        else cout<<a<<endl;
        return;
    }
    int cnt0=0,cnt1=0;
    for (int i=2;i<=n;i++){
        if (s[i]==s[i-1]){
            if (s[i]) cnt1++;
            else cnt0++;
        }
    }
    if (cnt0<=cnt1){
        ll res=(a+b)*cnt0;
        if (cnt0<cnt1) res+=b;
        if (b>c){
            int c0=0,c1=0;
            for (int i=1;i<=n;i++){
                c0+=(s[i]==0);
                c1+=s[i];
            }
            c0-=cnt0;
            c1-=cnt0;
            if (cnt0<cnt1) c1--;
            if (min(c0,c1-1)>0) res+=(b-c)*min(c0,c1-1);
        }
        cout<<res<<endl;
    } else {
        ll res=(a+b)*cnt1;
        res+=a;
        if (b>c){
            vector<int>v;
            int cnt=0;
            for (int i=1;i<=n;i++){
                if (s[i]){
                    if (cnt>0 && cnt<i-1) v.push_back(cnt);
                    cnt=0;
                } else cnt++;
            }
            sort(v.begin(),v.end());
            int can=cnt1;
            for (int &i:v){
                int cur=min(i-1,can);
                can-=cur;
                i-=cur;
                if (i==1) res+=b-c;
            }
        }
        cout<<res<<endl;
    }

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