#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x){
    char c = getchar();
    int p = 1;
    x = 0;
    while(!isdigit(c)){
        if(c == '-')p = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = getchar();
    }
    x *= p;
}
const int maxn = 100050;
priority_queue<int, vector<int>, greater<int> >qu;
vector<int>vec[maxn];
int a[maxn], b[maxn], n, k, cnt;
bool vis[maxn];
inline bool cmp(int A, int B){
    return b[A] < b[B];
}
signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    read(n), read(k);
    for(register int i = 1; i <= n; ++i){
        read(a[i]);
        vec[a[i]].push_back(i);
    }
    for(register int i = 1; i <= n; ++i){
        read(b[i]);
    }
    for(register int i = 1; i <= k; ++i){
        if(vec[i].size() >= 1){
            sort(vec[i].begin(), vec[i].end(), cmp);
            int sz = vec[i].size();
            for(register int j = 0; j < sz - 1; ++j){
                qu.push(b[vec[i][j]]);
            }
            vis[i] = 1;
        }
    }
    for(register int i = 1; i <= k; ++i){
        if(!vis[i])cnt++;
    }
    int ans = 0;
    while(!qu.empty() && cnt){
        ans += qu.top();
        qu.pop();
        cnt--;
    }
    printf("%lld\n", ans);
    return 0;
}