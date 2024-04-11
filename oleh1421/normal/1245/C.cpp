#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007ll;
ll dp[101010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[0]=1ll;
    dp[1]=1ll;
    for (int i=2;i<=100000;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    string s;cin>>s;
    ll res=1ll;
    int n=(int)s.size();
    vector<int>v;
    int cntn=0;
    int cntu=0;
    for (int i=0;i<n;i++){
        if (s[i]=='m' || s[i]=='w'){
            cout<<0;
            return 0;
        }
        if (s[i]=='n'){
            cntn++;
            v.push_back(cntu);
            cntu=0;
        } else if (s[i]=='u'){
            cntu++;
            v.push_back(cntn);
            cntn=0;
        } else {
            v.push_back(cntn);
            v.push_back(cntu);
            cntu=cntn=0;
        }
    }
    v.push_back(cntn);
    v.push_back(cntu);
    for (auto i:v){
        res*=dp[i];
        res%=mod;
    }
    cout<<res;
    return 0;
}