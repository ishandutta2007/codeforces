#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500500;
#define endl '\n'
int cnt[N*2];
void solve(){
    string s;cin>>s;
    int n=s.size();
    int sum=n;
    for (int i=0;i<n;i++){
        if (s[i]=='1'){
            cnt[sum]++;
            sum++;
        } else {
            sum--;
            cnt[sum]++;
        }
    }
    string res="";
    int cur=n;
    for (int it=0;it<n;it++){
        if (cnt[cur-1] && (!cnt[cur] || cnt[cur-1]>=2)){
            res+="0";
            cur--;
            cnt[cur]--;
        } else {
            res+="1";
            cnt[cur]--;
            cur++;
        }
    }
    cout<<res<<endl;
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