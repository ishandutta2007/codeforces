#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const ll mod=1000000007ll;
ll a[N];
ll pref[N];
ll pw[N];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;cin>>s>>t;
    pw[0]=1ll;
    pw[1]=29ll;
    pref[0]=0ll;
    pref[1]=(t[0]-'a'+1ll);
    for (int i=2;i<=t.size();i++){
        pw[i]=(pw[i-1]*pw[1])%mod;
        pref[i]=(pref[i-1]+pw[i-1]*(t[i-1]-'a'+1ll));
    }
    int cnt=0;
    for (auto i:s){
        cnt+=(i-'0');
    }
    int res=0;
    for (int r1=1;r1*cnt<t.size();r1++){
        int r0=(int)t.size()-r1*cnt;
        if (r0%((int)s.size()-cnt)) continue;
        r0/=(int)s.size()-cnt;
        int last=0;
        ll A=-1ll;
        ll B=-1ll;
        bool ok=true;
        for (int i=0;i<s.size();i++){
            if (s[i]=='1'){
                ll cur=(((pref[last+r1]-pref[last]+mod)%mod)*pw[(int)t.size()-last-r1])%mod;
                if (A!=-1 && A!=cur){
                    ok=false;
                    break;
                }
                A=cur;
                last+=r1;
            } else {
                ll cur=(((pref[last+r0]-pref[last]+mod)%mod)*pw[(int)t.size()-last-r0])%mod;
                if (B!=-1 && B!=cur){
                    ok=false;
                    break;
                }
                B=cur;
                last+=r0;
            }
        }
//        cout<<r1<<" "<<A<<" "<<B<<endl;
        ok&=(A!=B);
        res+=ok;
    }
    cout<<res<<endl;

    return 0;
}
///try to solve I
/*
3 1
1 1
1 2
2 1
1 3
3 1
*/