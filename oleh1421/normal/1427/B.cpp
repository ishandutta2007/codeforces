#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N],b[N];
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int cntL=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L') cntL++;
    }
//    cout<<cntL<<endl;
    if (cntL<=k){
        cout<<n+n-1<<endl;
        return;
    }
    if (cntL==n){
        cout<<max(min(n,k)*2-1,0)<<endl;
        return;
    }
    int cnt=0;
    vector<int>v;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L') cnt++;
        else {
            if (cnt<i && cnt>0) v.push_back(cnt);
            cnt=0;
        }
    }
    sort(v.begin(),v.end());
    int seg=0;
    int sum=0;
    for (int i:v){
        sum+=i;
        if (sum>k) break;
        seg++;
    }

    int res=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='W'){
            res++;
            if (i && s[i-1]=='W') res++;
        }
    }
//    cout<<res<<endl;
    cout<<res+k*2+seg<<endl;

//    int n;cin>>n;
//    for (int i=1;i<=n;i++) cin>>a[i];
//    sort(a+1,a+n+1);
//    int sum=0;
//    for (int i=1;i<=n;i++){
//        sum+=a[i];
//        if (sum==0){
//
//        }
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}