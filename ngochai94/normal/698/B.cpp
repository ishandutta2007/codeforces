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

int n,par[200005],ans,vst[200005];

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    int root=-1;
    cin>>n;
    For(i,1,1+n) {
        cin>>par[i];
        if(i==par[i]) {
            root=i;
        }
    }
    // if (root == -1) {
    //     root = 1;
    //     par[1]=1;
    //     vst[1]=1;
    //     ans=1;
    // }
    // vst[root]=1;
    if (root!=-1) vst[root]=1;
    For(i,1,1+n) if(!vst[i]) {
        int st=i;
        int cur=i;
        vst[cur]=-1;
        int pending=-1;
        while(1) {
            cur=par[cur];
            // cout<<cur<<endl;
            if(vst[cur]==1) break;
            if(vst[cur]==-1) {
                ans++;
                if (root==-1) root = cur;
                pending=cur;
                break;
            }
            vst[cur]=-1;
        }
        while(vst[st]==-1) {

            vst[st]=1;
            st=par[st];
        }
        if(pending!=-1) par[pending]=root;
    }
    cout<<ans<<endl;
    For(i,1,1+n) cout<<par[i]<<' ';
}