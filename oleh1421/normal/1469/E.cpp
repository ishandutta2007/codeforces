//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=2000010;
int a[N];
int pref[N];
mt19937 rnd(time(NULL));
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    pref[0]=0;
    for (int i=0;i<n;i++){
        a[i+1]=(s[i]=='0');
        pref[i+1]=pref[i]+a[i+1];
    }
    string t="";
    while ((int)t.size()+20<=k){
        t+="0";
    }
    int m=t.size();
    vector<int>v;
    for (int i=1;i+k-1<=n;i++){
        if (pref[i+m-1]==pref[i-1]){
            int mask=0;
            for (int j=i+m;j<=i+k-1;j++){
                mask*=2;
                mask+=a[j];
            }
            v.push_back(mask);
        }
    }
    int res;
    if (v.empty()){
        res=0;
    } else {
        sort(v.begin(),v.end());
        res=v.back()+1;
        if (v[0]) res=0;
        else {
            for (int i=1;i<v.size();i++){
                if (v[i]>v[i-1]+1){
                    res=v[i-1]+1;
                    break;
                }
            }
        }
    }
    vector<int>ans;
    for (int i=1;i<=k;i++){
        ans.push_back(res%2);
        res/=2;
    }
    if (res){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    reverse(ans.begin(),ans.end());
    for (int i:ans) cout<<i;
    cout<<endl;


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
4 2
0110
*/