#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1<<12;
const int MAXM = 1<<16;
const int B = 1<<8;

int n,q,a[MAXN+5],bel[MAXN+5],ps[MAXN+5];
std::vector<P> v;

inline int merge(int x,int y){
    if(!x) return y;
    if(!y) return x;
    v.pb(MP(x,y));return v.size()+n;
}

struct Node{
    std::vector<int> S;
    int ps[B][B];
    Node(int x=-1){if(x != -1) S.pb(::ps[x]),ps[0][0] = ::ps[x]+1;}
    inline int query(int l,int r){
        l = std::lower_bound(all(S),l)-S.begin();r = std::upper_bound(all(S),r)-S.begin()-1;
        if(l > r) return 0;
        return ps[l][r];
    }

    friend Node operator + (Node A,Node B){
        Node C;C.S.resize(A.S.size()+B.S.size());
        merge(all(A.S),all(B.S),C.S.begin());
        FOR(i,0,(int)C.S.size()-1){
            FOR(j,i,(int)C.S.size()-1){
                int l = C.S[i],r = C.S[j];
                C.ps[i][j] = merge(A.query(l,r),B.query(l,r));
            }
        }
        return C;
    }
}b[(MAXN/B)+5];

inline Node work(int l,int r){
    if(l == r) return Node(l);
    int mid = (l + r) >> 1;
    return work(l,mid)+work(mid+1,r);
}
int ans[MAXM+5];

int main(){
    scanf("%d%d",&n,&q);FOR(i,0,n-1) scanf("%d",a+i),a[i]--,ps[a[i]] = i;
    FOR(i,0,n-1) bel[i] = i/B;int m = bel[n-1];
    FOR(i,0,m) b[i] = work(i*B,std::min(n-1,(i+1)*B-1));
    FOR(i,1,q){
        int l,r;scanf("%d%d",&l,&r);--l;--r;
        int res = 0;
        FOR(i,0,m) res = merge(res,b[i].query(l,r));
        ans[i] = res;
    }
    printf("%d\n",n+(int)v.size());
    for(auto x:v) printf("%d %d\n",x.fi,x.se);
    FOR(i,1,q) printf("%d ",ans[i]);puts("");
    return 0;
}