#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=1010;
vector<int>g[N];
int d[N];
vector<int>u;
int p[N];
int sz[N];
bool used[N];
void dfs(int v,int pr){
    u.push_back(v);
    sz[v]=1;
    p[v]=pr;
    for (auto to:g[v]){
        if (to==pr) continue;
        if (!used[to]) {
            dfs(to,v);
            sz[v]+=sz[to];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    dfs(1,-1);
    int cnt=0;
    while (u.size()>3){
        int k=u.size();
        int root=-1;
        int prev=-1;
        for (auto i:u){
            if (sz[i]>=2 && k-sz[i]>=2){
                cout<<"? "<<i<<" "<<p[i]<<endl;
                cnt++;
                if (cnt>n/2) exit(1);
                int x;cin>>x;
                if (x==i){
                    root=i;
                    prev=p[i];
                    used[p[i]]=true;
                } else {
                    root=p[i];
                    prev=i;
                    used[i]=true;
                }
                break;
            }
        }
        if (root==-1) break;
        u.clear();
        dfs(root,prev);
    }
    if (u.size()==1){
        cout<<"! "<<u[0];
        return 0;
    }
    vector<int>l;
    int mid=-1;
    for (auto i:u){
        int cnt=0;
        for (auto to:g[i]){
            if (!used[to]) cnt++;
        }
        if (cnt==1) l.push_back(i);
        else mid=i;

    }
    for (int i=0;i+1<l.size();i+=2){
        cout<<"? "<<l[i]<<" "<<l[i+1]<<endl;
        int x;cin>>x;
        if (x==l[i] || x==l[i+1]){
            cout<<"! "<<x<<endl;
            return 0;
        }
    }
    if (l.size()%2){
        cout<<"? "<<l.back()<<" "<<mid<<endl;
        int x;cin>>x;
        cout<<"! "<<x<<endl;
        return 0;
    }
    cout<<"! "<<mid<<endl;
    return 0;
}