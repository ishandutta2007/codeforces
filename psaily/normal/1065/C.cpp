#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
   
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int N=2e5+5;
int n,k,mi=inf,mx;
int a[N];
struct bit {
    ll sum[N];
    int lowbit(int x) {return x&(-x);}   
    void update(int x,int a) {
        if (!x) return;
        for (;x<N;x+=lowbit(x)) sum[x]+=a;
    }
    int query(int x) {
        ll res=0;
        for (;x;x-=lowbit(x)) res+=sum[x];
        return res;
    }
    void gao(int l,int r) {
        update(l,+1);
        update(r+1,-1);
    } 
}bit;
 
int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n+1) {
        scanf("%d",&a[i]); mi=min(mi,a[i]),mx=max(mx,a[i]);
        bit.gao(1,a[i]);
    }
    // debug(mx);
    int now=mx,ans=mx==mi?0:1;
    ll cur=0;
    while (now>mi) {
        ll b=bit.query(now);
        if (cur+b>k) cur=b,ans++;
        else cur+=b;
        now--;
    }
    printf("%d\n",ans);
    return 0;   
}