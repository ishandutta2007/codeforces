#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,par[100005],fav[100005],m,x,y;
int anc[100005],rnk[100005],allow[100005],wan,cur;
vector<int> child[100005];
queue<int> q;
stack<int> ans;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    reset(par,-1);
    while(m--) {
        cin>>x>>y;
        par[y]=x;
        child[x].pb(y);
    }
    For(i,1,1+n) if(par[i]==-1) {
        q.push(i);
        anc[i]=i;
        while(!q.empty()) {
            cur=q.front();q.pop();
            for(int nex:child[cur]) {
                anc[nex] = anc[cur];
                rnk[nex] = rnk[cur] + 1;
            }
        }
    }

    For(i,1,1+n) cin>>fav[i];
    // cout<<fav[3]<<endl;
    For(i,1,1+n) if(par[i]==-1) {
        q.push(i);
        while(!q.empty()) {
            cur = q.front(); q.pop();
            wan = fav[cur];
            // cout<<cur;
            // if(anc[wan]!=anc[cur]||rnk[wan]>rnk[cur]) {
            //     cout<<-1;return 0;
            // }

            if(par[cur]!=-1) {
                int pp=par[cur];
                // cout<<wan<<' '<<cur<<' '<<pp<<' '<<fav[pp]<<endl;
                
                if(fav[pp]!=wan&&wan!=cur) {
                    cout<<-1;return 0;
                }
            }
            if(wan==cur) ans.push(cur);
            for(int nex:child[cur]) q.push(nex);
        }
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()) {
        cout<<ans.top()<<endl;
        ans.pop();
    }
}