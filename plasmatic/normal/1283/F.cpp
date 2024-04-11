#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
pair<pii,int> dsu[MAXN];
int fir[MAXN];
int find(int a){
    if(dsu[a].first.first==a)return a;
    return dsu[a].first.first=find(dsu[a].first.first);
}
set<pii> q;
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    q.erase({dsu[bp].second,b});
   // if(dsu[ap].first.second<dsu[bp].first.second)swap(ap,bp);
    dsu[ap].first.second+=dsu[bp].first.second;
    dsu[bp].first.first=ap;
    dsu[ap].second=max(dsu[ap].second,dsu[bp].second);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<int> leaves;
    for(int i=1;i<=n;i++)leaves.insert(i),dsu[i]={{i,1},i},fir[i]=INT_MAX;
    for(int i=1;i<n;i++){
        cin>>arr[i];
        fir[arr[i]]=min(fir[arr[i]],i);
        leaves.erase(arr[i]);
    }

    vector<pii> edges;
    for(int x:leaves){
        q.insert({x,x});
    }
    for(int i=n-1;i>=1;i--){
        auto cur=*q.begin();
        q.erase(q.begin());
        if(find(arr[i])==find(cur.second)){
           // auto te=cur;
            if(sz(q)==0){
                printf("-1\n");
                return 0;
            }
            cur=*q.begin();
            q.erase(q.begin());
        }
        edges.push_back({cur.second,arr[i]});
        uni(arr[i],cur.second);
        if(arr[i]!=find(arr[i])){
            printf("-1\n");
            return 0;
        }
        if(i==fir[arr[i]])q.insert({dsu[find(cur.second)].second,arr[i]});
    }
    if(dsu[find(arr[1])].second!=n){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",arr[1]);
    for(auto x:edges)printf("%d %d\n",x.first,x.second);
    return 0;
}