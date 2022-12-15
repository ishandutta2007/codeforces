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

int n,qq,t,x,unread[300005],pending[300005],ans,cur,cnt;
queue<int> q;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d", &n, &qq);
    while(qq--) {
        scanf("%d %d", &t, &x);
        if(t==1) {
            q.push(x);
            unread[x]++;
            ans++;
            cnt++;
        } else if(t==2) {
            pending[x]+=unread[x];
            ans-=unread[x];
            unread[x]=0;
        } else {
            assert(x<=cnt);
            // cout<<'a'<<min((int)q.size(),x-cur)<<endl;
            int loop = x-cur;
            For(i,0,loop) {
                int tmp = q.front(); q.pop();
                // cout<<tmp<<' '<<pending[tmp]<<' '<<unread[tmp]<<endl;
                if(pending[tmp]) pending[tmp]--;
                else {
                    ans--;
                    unread[tmp]--;
                }
            }
            cur=max(cur,x);
        }
        printf("%d\n", ans);
    }
}