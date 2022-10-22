#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define loop(i,s,e) for(int i=(s);i<(e);i++)
using namespace std;
const int INF=1e18;


struct DSU{
    int sz;
    vector<int> next;
    DSU(int n){
        sz=n;
        next.resize(sz,0);
        for(int i=0;i<n;i++) next[i]=i;
    }
    int getNext(int a){
        if (a>=sz) return a;
        if (next[a]==a) return a;
        return next[a]=getNext(next[a]);
    }
    void print(){
        cout<<"PRINT NEXT: ";
        for(int i=0;i<sz;i++) cout<<next[i]<<" ";
        cout<<endl;
    }
};
vi ans;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    int x,l,r;
    ans.resize(n);
    DSU next(n);
    //next.print();
    loop(i,0,m) {
        //cout<<i<<endl;
        cin >>l>>r>>x;l--;r--;x--;
        int cur=next.getNext(l);
        while(cur<=r){
            if (cur==x){
                next.getNext(i);
                cur=cur+1;
            }
            else{
                ans[cur]=x+1;
                next.next[cur]=cur+1;
            }
            cur=next.getNext(cur);
        }
        //next.print();
        //cout<<endl;
    }
    //cout<<"end"<<endl;
    loop(i,0,n) cout << ans[i]<<" ";
    return 0;
}