#include <bits/stdc++.h>
#define int int64_t
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n,t,cur,cnt=1;cin>>n;
    int x,y,sz;
    vi a(n);
    vector<vi> g(n);
    for(int i=0;i<n-1;i++) {
        cin>>x>>y;x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i=0;i<n;i++) {
        cin>>t;
        a[i]=t-1;
    }
    queue<int> q;
    vi check(n,0);
    vi nei;
    q.push(0);
    check[0]=1;
    if (a[0]!=0) return (cout<<"No",0);
    //cout<<":("<<endl;
    while(!q.empty()){
        cur=q.front();
        //cout<<cur<<endl;
        q.pop();
        nei=g[cur];
        sort(nei.begin(),nei.end());
        sz=0;
        for(int i=0;i<nei.size();i++){
            if (check[nei[i]]==0) sz++;
        }
        //cout<<sz<<endl;
        for(int i=0;i<sz;i++){
            if (!binary_search(nei.begin(),nei.end(),a[cnt+i])) return (cout<<"No",0);
            else{
                check[a[cnt+i]]=1;
                q.push(a[cnt+i]);
            }
        }
        cnt+=sz;
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*
4
1 2
1 3
2 4
1 2 3 4
*/