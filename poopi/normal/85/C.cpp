                                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <map>
using namespace std;

#define int64 long long
#define P pair<int64, int>

int n, m, rt;
int ch[100010][2];
int ref[100010];
int64 val[100010];
int64 dp[100010];
int64 depth[100010];
P arr[100010];
queue <int> q;
int par[100010];

int main(){
    memset(ch, -1, sizeof ch);
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &par[i], &a);
        par[i]--;
        arr[i] = P(a, i);
        val[i] = a;
    }
    for(int i = 0; i < n; i++){
        if(par[i] >= 0){
            if(val[par[i]] > val[i])
                ch[par[i]][0] = i;
            else ch[par[i]][1] = i;
        }
        else rt = i;
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        ref[arr[i].second] = i;
    dp[rt] = 0;
    depth[rt] = 0;
    q.push(rt);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(ch[t][0] == -1)
            continue;
        dp[ch[t][0]] = dp[t] + arr[ref[t] + 1].first;
        depth[ch[t][0]] = depth[t] + 1;
        q.push(ch[t][0]);
        dp[ch[t][1]] = dp[t] + arr[ref[t] - 1].first;
        depth[ch[t][1]] = depth[t] + 1;
        q.push(ch[t][1]);
    }
    //for(int i = 0; i < n; i++){
    //  cout << arr[i].first << ' ' << arr[i].second << endl;
    //}
    cin >> m;
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(arr[mid].first > a)
                r = mid - 1;
            else l = mid;
        }
        int t = arr[l].second;
        if(ch[t][1] != -1)
            t = arr[l + 1].second;
        //cout << l << ' ' << t << endl;
        printf("%.9lf\n", (double)dp[t] / depth[t]);
    }
    return 0;
}