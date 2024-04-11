//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=2000010;
ll mod=1ll;
const ll Mod=1000000007;
int len[N];
int n,tt;
string s0,t;
ll suf[N];
ll pref[N];
bool ok[N];
ll dp[N];
ll pp[N];
ll pw[N];
ll SSS[N];
ll cnt[100010][30];
void solve(){
    int ind;cin>>ind;
    string s;cin>>s;

    int k=0;
    int m=s.size();
    if (m>len[ind]){
        cout<<0<<endl;
        return;
    }
    while (k+1<=ind && len[k]<=m) k++;
//    k=ind;
    suf[m+1]=0ll;
    for (int i=m;i>=1;i--){
        suf[i]=(suf[i+1]*29ll+(s[i-1]-'a'+1ll))%mod;
    }
    for (int i=1;i<=m;i++) ok[i]=false;
    ll Hash=0ll;
    for (int i=1;i<=m;i++){
        if (Hash==SSS[i-1] && suf[i+1]==pref[m-i]) ok[i]=true;
        Hash*=29ll;
        Hash+=(s[i-1]-'a'+1ll);
        Hash%=mod;
    }
    dp[0]=0;
    ll cur=suf[1];
    for (int i=1;i+m-1<=s0.size();i++){
        ll A=(pp[i+m-1]-pp[i-1]+mod)%mod;
        if (A==cur) dp[0]++;
        cur*=29ll;
        cur%=mod;
    }
//    for (int i=1;i<=m;i++) cout<<ok[i];
//    cout<<endl;
    for (int i=1;i<=k;i++){
        dp[i]=(dp[i-1]*2ll)%Mod;
        for (int j=1;j<=m;j++){
            if (t[i-1]==s[j-1] && ok[j] && max(j-1,m-j)<=len[i-1]) dp[i]++;
        }
        dp[i]%=Mod;
    }
    ll res=dp[k]*pw[ind-k]%Mod;

    for (int j=1;j<=m;j++){
        ll Cnt=((cnt[ind][s[j-1]-'a']-((cnt[k][s[j-1]-'a']*pw[ind-k])%Mod)+Mod)%Mod);
        if (ok[j]) res+=Cnt,res%=Mod;
    }
    cout<<res<<endl;




}
mt19937 rnd(time(NULL));
int32_t main()
{
    do{
        mod=rnd()%1000000000000001ll;
    }while (mod%29ll==0 || mod%2ll==0 || mod%3ll==0 || mod<1000000000ll);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>tt;
    cin>>s0>>t;
    len[0]=s0.size();
    for (int i=1;i<=n;i++){
        len[i]=min(N,len[i-1]*2+1);
    }
    int k=0;
    while (k+1<=n && len[k]<N) k++;
//    if (k==n) exit(1);
    string S=s0;

    ll ppp=1ll;
    pp[0]=0ll;
    for (int i=1;i<=S.size();i++){
        pp[i]=(pp[i-1]+ppp*(S[i-1]-'a'+1ll))%mod;
        ppp*=29ll;
        ppp%=mod;
    }

    for (int i=1;i<=k;i++){
        S+=t[i-1];
        S+=S;
        S.pop_back();
    }
    string S1=S;
    reverse(S1.begin(),S1.end());
    while (S1.size()>=N) S1.pop_back();
    while (S.size()>=N) S.pop_back();
    ll p=1ll;
    pref[0]=0ll;
    for (int i=1;i<=S.size();i++){
        pref[i]=(pref[i-1]+p*(S[i-1]-'a'+1ll))%mod;
        p*=29ll;
        p%=mod;
    }
    p=1ll;
    SSS[0]=0ll;
    for (int i=1;i<=S1.size();i++){
        SSS[i]=(SSS[i-1]+p*(S1[i-1]-'a'+1ll))%mod;
        p*=29ll;
        p%=mod;
    }
    pw[0]=1ll;
    for (int i=1;i<N;i++){
        pw[i]=(pw[i-1]*2ll)%Mod;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<30;j++){
            cnt[i][j]=(cnt[i-1][j]*2ll)%Mod;
        }
        cnt[i][t[i-1]-'a']++;
        cnt[i][t[i-1]-'a']%=Mod;
    }
    while (tt--){
        solve();
    }

    return 0;
}
/*

3 0
aa
bcd
*/