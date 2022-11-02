#include<bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#define pb push_back
#define int long long

const int N = 2e5 + 10;
vector<int> g[N];
int sum[N];
int cnt[N];
int a[N];
bool x = 0;

void zhfs(int v, int p){
    bool was = 1;
    sum[v] = a[v];
    for (auto to : g[v]){
        if (to != p){
            zhfs(to, v);
            cnt[v] += cnt[to];
            was = 0;
            sum[v] += sum[to];
        }
    }
    if (was){
        cnt[v] = 1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        g[a].pb(i);
        g[i].pb(a);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (mx == 0){
        cout << 0 << endl;
        return 0;
    }
    zhfs(1, -1);
    int l = 0, r = 1e15;
    while(r - l > 1){
        int mid = (r + l) / 2;
        x = 0;
        for (int i = 1; i <= n; i++){
            if ((sum[i] + mid - 1) / mid > cnt[i]){
                x = 1;
            }
        }
        if (!x){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}