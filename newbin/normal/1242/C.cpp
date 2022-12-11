#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5 + 50;
const int inf = 0x3f3f3f3f;
map<int, int> mp;
struct node{
    vector<int> ned;
}q[maxn];
int tot = 0;
int n;
int a[maxn];
int cnt = 0;
ll sum;
ll D[16];
ll to(int x){
    int id = mp[x];
    return sum - (D[id]-x);
}
int dp[1<<16];
vector<int> path;
void dfs(ll x, int mask){
    if(x > inf) return;
    if(mp.find(x) == mp.end()) return;
    int id = mp[x];
    if((mask>>id)&1){//
        int st = -1;
        for(int i = 0; i < path.size(); ++i){
            if(path[i] == x) st = i;
        }
        if(st == -1) return;//
        for(int i = 0; i < st; ++i) mask ^= (1<<mp[path[i]]);
        if(dp[mask]) return;//
        ++tot;
        dp[mask] = -tot;
        for(int i = st; i < path.size(); ++i){
            q[tot].ned.push_back(path[i]);
        }
        return;
    }
    path.push_back(x);
    dfs(to(x), mask|(1<<id));
}
vector<int> ans;
void go(int mask){
    if(dp[mask] < 0){
        int id = -dp[mask];
        for(int i = 0; i < q[id].ned.size(); ++i){
            ans.push_back(q[id].ned[i]);
        }return;
    }
    go(dp[mask]); go(mask^dp[mask]);
}
int main()
{
	cin>>n;
	sum = 0;
	for(int i = 0; i < n; ++i){
        int k; scanf("%d", &k);
        while(k--){
            scanf("%d", &a[cnt]);
            mp[a[cnt]] = i;
            sum += a[cnt];
            D[i] += a[cnt];
            cnt++;
        }
	}
	if(sum%n != 0){
        printf("No\n"); return 0;
	}
	sum /= n;
	for(int i = 0; i < cnt; ++i){
        path.clear();
        dfs(a[i], 0);
	}
	for(int mask = 1; mask < (1<<n); ++mask){
        if(dp[mask]) continue;
        for(int sub = (mask-1)&mask; sub; sub = (sub-1)&mask){
            if(dp[sub] && dp[mask^sub]){

                dp[mask] = sub;
                break;
            }
        }
	}
	if(!dp[(1<<n)-1]) cout<<"No"<<endl;
	else{
        cout<<"Yes"<<endl;
        go((1<<n)-1);
        int pre[15], val[15];
        for(int i = 0; i < ans.size(); ++i){
            int x = ans[i];
            int id = mp[x];
            int v = to(x);
            val[id] = x;
            pre[mp[v]] = id;
        }
        for(int i = 0; i < n; ++i){
            cout<<val[i]<<" "<<pre[i]+1<<endl;
        }
	}
	//for(int i = 0; i < (1<<n); ++i) cout<<"i:"<<i<<" dp:"<<dp[i]<<endl;
}