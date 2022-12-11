#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 1e5 + 50;
const int inf = maxn;
ll a[maxn];
int cnt = 0;
int mp[250][250];
int dis[250][250];
int ans;
void floyed(){
    for(int k = 0; k < cnt; ++k){
        for(int i = 0; i < k; ++i){
            for(int j = i+1; j < k; ++j){
                ans = min(ans , mp[k][i] + mp[k][j] + dis[i][j]);
            }
        }
        for(int i = 0; i < cnt; ++i){
            for(int j = 0; j < cnt; ++j){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
             }
        }
    }
}
int main()
{
	int n;cin>>n;
	while(n--){
        ll x; scanf("%I64d", &x);
        if(x == 0) continue;
        a[cnt++] = x;
	}
	if(cnt > 200){
        printf("3\n"); return 0;
	}
	for(int i = 0; i < cnt; ++i)
        for(int j = 0; j <cnt; ++j) {
        mp[i][j] = mp[j][i] = inf;
        dis[i][j] = dis[j][i] = inf;
	}
	for(int i = 0; i < cnt; ++i){
        for(int j = i+1; j <cnt; ++j){
            if(a[i] & a[j]) {
                mp[i][j] = mp[j][i] = 1;
                dis[i][j] = dis[j][i] = 1;
            }
        }
	}
	ans = inf;
	floyed();
	if(ans == inf) ans = -1;
	cout<<ans<<endl;
}