#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=300010;
int a[N];
map<string,int>mp;
int F(string s){
    if (s.empty()) return 0;
    if (mp.find(s)!=mp.end()) return mp[s];
    int res=s.size();
    for (int l=0;l<s.size();l++){
        for (int r=l;r<s.size();r++){
            if (r>l && s[r]==s[r-1]) break;
            string t="";
            for (int i=0;i<s.size();i++){
                if (i<l || i>r) t+=s[i];
            }
            res=min(res,F(t)+1);
        }
    }
    return mp[s]=res;
}
void ans(int n,int sum,int cnt,int a1,int an){
    if (sum==n || sum==0){
        cout<<n<<endl;
    } else {
        int seg1=(cnt+1+a1)/2;
        int seg0=cnt+1-seg1;
        if (a1) seg1--;
        else seg0--;
        if (an) seg1--;
        else seg0--;
        cout<<max(sum-seg0,(n-sum)-seg1)<<endl;
    }

}
int s[N];
int cn[N];
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
        s[i]=s[i-1]+a[i];
    }
    cn[1]=0;
    for (int i=2;i<=n;i++) cn[i]=(cn[i-1]+(a[i]^a[i-1]));
    for (int it=1;it<=q;it++){
        int l,r;cin>>l>>r;
        ans(r-l+1,s[r]-s[l-1],cn[r]-cn[l],a[l],a[r]);
    }


}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/