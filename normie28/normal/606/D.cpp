#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second
#define endl "\n";
using namespace std;
 
const double pi=acos(-1);
const int N=2e5+7,mod=1000000007,M=2e9;
 
int n,m,u,v;
struct edge{
    int w,id;
    bool st;
 
    operator<(const edge& a)const{
        if(a.w==w)
            return a.st;
        return a.w<w;
    }
}a[N],t;
 
priority_queue<edge> q;
pii ans[N];
stack<pii> tmp;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        a[i]={u,i,v};
        q.push(a[i]);
    }
    v=2;
 
    while(!q.empty()){
        t=q.top();
        q.pop();
        if(t.st){
            ans[t.id]={v-1,v};
            u=v-2;
            while(u&&tmp.size()<m)
                tmp.push({u--,v});
            v++;
        }
        else{
            if(tmp.empty())
                return puts("-1");
            else{
                ans[t.id]=tmp.top();
                tmp.pop();
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i].ff<<' '<<ans[i].ss<<endl;
    }
}