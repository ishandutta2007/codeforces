#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli arr[MAXN];
lli where[MAXN];
int n,m;
lli getdis(lli a){
    lli loc=lower_bound(arr,arr+n,a)-arr;
    lli dis=LLONG_MAX;
    if(loc<n)dis=abs(arr[loc]-a);
    loc--;
    if(loc>=0)dis=min(dis,abs(arr[loc]-a));
    return dis;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    set<lli> used;
    set<pair<lli,pll>> pos;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        used.insert(arr[i]);
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int l=arr[i]-1;
        if(!used.count(l)) {
            used.insert(l);
            pos.insert({getdis(l), {l, -1}});
        }
        int r=arr[i]+1;
        if(!used.count(r)) {
            used.insert(r);
            pos.insert({getdis(r), {r, 1}});
        }
    }
    lli tot=0;
    for(int i=0;i<m;i++){
        auto cur=*pos.begin();
        pos.erase(pos.begin());
        tot+=cur.first;
        where[i]=cur.second.first;
        cur.second.first+=cur.second.second;
        if(!used.count(cur.second.first)) {
            used.insert(cur.second.first);
            pos.insert({getdis(cur.second.first), {cur.second.first, cur.second.second}});
        }
    }
    printf("%lli\n",tot);
    for(int i=0;i<m;i++)printf("%lli ",where[i]);
    return 0;
}