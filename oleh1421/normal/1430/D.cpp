#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int>v;
    int cnt=1;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]){
            v.push_back(cnt);
            cnt=1;
        } else {
            cnt++;
        }
    }
    v.push_back(cnt);
    int k=v.size();
    int sum=n-k;
    int pos=0;
    int res=0;
    int pos1=0;
    while (pos<k){
        while (pos1<k && v[pos1]==1) pos1++;
        if (pos1<k) v[pos1]--;
        else pos++;
        if (pos<k) pos++;
        pos1=max(pos1,pos);
        res++;
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