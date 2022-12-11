#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int a[7];
int vis[7][7];
int u[100], v[100];
int n, m;
int ans = 0;
void dfs(int pos){
    if(pos > n ){
        memset(vis,0,sizeof vis);
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            int x = u[i];
            int y = v[i];
            int ax = a[x], ay = a[y];
            if(vis[ax][ay] || vis[ay][ax]) continue;
            cnt++;
            vis[ax][ay] = vis[ay][ax] = 1;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = 1; i <= 6; ++i){
        a[pos] = i;
        dfs(pos+1);
    }return;
}
int main()
{
    ans = 0;
	cin>>n>>m;
	for(int i = 0; i < m; ++i) {
        cin>>u[i]>>v[i];
	}
	dfs(1);
	cout<<ans<<endl;
}