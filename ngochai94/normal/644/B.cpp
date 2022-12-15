#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,b,t[200005],d[200005],qf,ans[200005];
queue<long long> q;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>b;
    For(i,0,n) cin>>t[i]>>d[i];
    qf=0;
    reset(ans,-1);
    For(i,0,n) {
        while(qf<=t[i]&&!q.empty()) {
            int p = q.front();
            q.pop();
            qf+=d[p];
            ans[p]=qf;
        }
        if(q.empty() && qf<=t[i]) {
            qf = t[i]+d[i];
            ans[i]=qf;
        } else if( q.empty()) {
            q.push(i);
        } else {
            if(q.size()<b) q.push(i);
        }
    }
    while(!q.empty()) {
        int p=q.front();
        q.pop();
        qf+=d[p];
        ans[p]=qf;
    }
    For(i,0,n) cout<<ans[i]<<' ';
}