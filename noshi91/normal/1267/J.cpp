#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
 
main(){
    int t ; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> mp;
        rep(i,n){
            int a;cin>>a;
            mp[a]++;
        }
        vector<int> v;
        for(auto e:mp)v.push_back(e.second);
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        int k=v[0];
        queue<int> q;
        for(int i=1;i*i<=k;i++){
            q.push(k/i);
            if(k%i==0 && k/i-i>0)q.push(k/i-1);
        }
        for(int i=1;i*i<=k;i++){
            if(i)
            q.push(i);
        }
        while(!q.empty()){
            int s=q.front();q.pop();
            // cout<<s<<endl;
            bool flag=true;
            for(auto e:v){
                if(e/s<e%s){
                    flag=false;break;
                }
            }
            if(flag){
                int aaa=0;
                s++;
                for(auto e:v){
                    int l=e/(s-1)-e%(s-1);
                    int r=e%(s-1);
                    int T=l/s;
                    l=l%s;
                    r=r+(s-1)*T;
                    aaa += l+r;
                }
                ans=min(ans,aaa);
            }
        }
        cout<<ans<<endl;
        // cout<<ans<<" ";
        // cout<<aaa<<endl;
    }
}