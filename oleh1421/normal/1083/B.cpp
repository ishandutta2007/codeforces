#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
vector<int> f(string s,int n){
          vector<int>v;
          int cur=0;
          if (s[0]=='b') cur=1;
          v.push_back(cur);
          for (int i=1;i<n;i++){
              if (s[i]=='a'){
                 cur=cur*2;
              } else {
                 cur=cur*2+1;
              }
              v.push_back(cur);
          }
          return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    string a;cin>>a;
    string b;cin>>b;
    vector<int>v;
    int cur1=0;
    if (a[0]=='b') cur1=1;
    int cur2=0;
    if (b[0]=='b') cur2=1;
    int res=min(cur2-cur1+1,k);
    for (int i=1;i<n;i++){
        if (cur2-cur1+1<k){
        if (a[i]=='a'){
            cur1=cur1*2;
        } else {
            cur1=cur1*2+1;
        }
        if (b[i]=='a'){
            cur2=cur2*2;
        } else {
            cur2=cur2*2+1;
        }
        }
        res+=min(cur2-cur1+1,k);
    }
    cout<<res;
    return 0;
}