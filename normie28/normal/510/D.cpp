#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL card[305],cost[305],res;
map<LL,LL>mp;
map<LL,LL>::iterator it;
int n,top;
bool flag;
pair<LL,LL>p[90005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>card[i];
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=1;i<=n;i++){
        for(it=mp.begin();it!=mp.end();it++){
            LL pos=__gcd(it->first,card[i]);
            p[++top]=make_pair(pos,it->second+cost[i]);
        }
        p[++top]=make_pair(card[i],cost[i]);
        for(int j=1;j<=top;j++)
            if(mp.count(p[j].first))mp[p[j].first]=min(mp[p[j].first],p[j].second);
            else mp[p[j].first]=p[j].second;
        top=0;
    }
    for(it=mp.begin();it!=mp.end();it++){
        if(it->first==1){
            flag=1;
            res=it->second;
            break;
        }
    }
    if(flag==0) {cout<<-1; return 0;}
    cout<<res;
}