#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)

main(){
    int n , l , k;
    cin>> n>>l>>k;
    string s; cin>>s;
    sort(s.begin(),s.end());
    int now=-1;
    vector<string> ans(n);
    int kk=k;
    rep(i,l){
        char next=s[now+k];
        int cnt=0;
        rep(j,k){
            if(s[now+j+1]==next)cnt++;
            ans[kk-k+j].push_back(s[now+j+1]);
        }
        now=now+k;
        k=cnt;
    }
    int p=0;
    rep2(i,now+1,n*l-1){
        while(ans[p].size()==l)p++;
        ans[p].push_back(s[i]);
    }
    sort(ans.begin(),ans.end());
    for(auto e:ans)cout<<e<<endl;
}