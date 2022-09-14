#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=1000100;
int a[N];
int cnt[N];

int pref[N];

void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    for (int i=0;i<k;i++) cnt[i]=0;
    int sum=0;
    for (int i=0;i<n;i++){
        cnt[i%k]+=a[i];
        sum+=a[i];
    }
    int res=sum;
    for (int i=0;i<k;i++){
        vector<int>v;
        for (int j=i;j<n;j+=k) v.push_back(a[j]);
        vector<int>suf;
        int cnt0=0;
        int cnt1=0;
        int mn=0;
        for (int j=(int)v.size()-1;j>=0;j--){
            if (v[j]) cnt1++;
            else cnt0++;
            mn=min(mn,cnt1-cnt0);
            suf.push_back(cnt0+mn);

        }
        res=min(res,sum-cnt[i]+suf.back());
        int cur=0;
        for (int j=0;j+1<v.size();j++){
            cur+=v[j];
            res=min(res,sum-cnt[i]+cur+suf[v.size()-j-2]);
        }
        //cur+=1-v.back();
        //res=min(re)
    }
    cout<<res<<endl;

}
int main()
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