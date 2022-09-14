//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
int cnt[6];
int p[N];
bool used[N];
int calc(){
    int ans=0;
    ans+=cnt[4];
    if (cnt[1]+cnt[4]<cnt[2]){
        ans+=cnt[2];
    } else {
        ans+=cnt[2];
        ans+=((cnt[1]+cnt[4]-cnt[2])/3)*2;
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    for (int i=0;i<6;i++) cnt[i]=0;
    for (int i=1;i<=n;i++){
        cin>>p[i];
        used[i]=false;
    }
    ll last=n%3+3;
    if (last==5) last=2;
    ll res=1ll;
    for (int i=1;i<=(n-last)/3;i++) res=(res*3ll)%mod;
    res*=last;
    res%=mod;
    int add=0;
    bool was=false;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        int x=i;
        int len=0;
        while (!used[x]){
            used[x]=true;
            x=p[x];
            len++;
        }
        if (len<3) cnt[len]++;
        else if (len%3==1){
            add+=len/3-1;
            cnt[4]++;
            was=true;
        } else if (len%3==0){
            add+=len/3-1;
            was=true;
        } else {
            add+=len/3;
            cnt[2]++;
            was=true;
        }
    }
    int ans=1000000001;
    if (n%3==0){
        ans=add+calc();
    } else if (n%3==2){
        add+=cnt[4];
        cnt[1]+=cnt[4];
        cnt[4]=0;
        if (cnt[2]){
            cnt[2]--;
            int cur=add+calc();
            ans=min(ans,cur);
            cnt[2]++;
        }
        if (cnt[1]>=2){
            cnt[1]-=2;
            int cur=add+1+calc();
            ans=min(ans,cur);
            cnt[1]+=2;
        }
    } else {
//        cout<<add<<" "<<cnt[1]<<endl;
//        cout<<"OK\n";
        if (was && cnt[1]) {
            cnt[1]--;
            ans=min(ans,add+1+calc());
            cnt[1]++;
        }
        if (cnt[4]){
            cnt[4]--;
            ans=min(ans,add+calc());
            cnt[4]++;
        }
        if (cnt[2]>=2){
            cnt[2]-=2;
            ans=min(ans,add+calc());
            cnt[2]+=2;
        }
        if (cnt[2] && cnt[1]>=2){
            cnt[2]--;
            cnt[1]-=2;
            ans=min(ans,add+1+calc());
            cnt[2]++;
            cnt[1]+=2;
        }
        if (cnt[1]>=4){
            cnt[1]-=4;
            ans=min(ans,add+2+calc());
            cnt[1]+=4;
        }
    }
    cout<<res<<" "<<ans<<endl;


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
/*
1
5
2 3 4 5 1
*/