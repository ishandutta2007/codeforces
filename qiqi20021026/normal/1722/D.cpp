#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int n; string st; cin>>n>>st;
        long long ans=0;
        priority_queue<int> pq;
        for (int i=0,now=0;i<n;++i){
            if (st[i]=='L'){
                ans+=i;
                pq.push(n-1-i-i);
            }
            else{
                ans+=n-1-i;
                pq.push(i-(n-1-i));
            }
        }
        for (int i=1;i<=n;++i){
            int x=pq.top(); pq.pop();
            ans+=x>0?x:0;
            cout<<ans<<" \n"[i==n];
        }
    }
}