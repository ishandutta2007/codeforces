#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
struct segment_tree{
    int mi[maxn<<2];
    void up(int rt){mi[rt] = min(mi[rt<<1],mi[rt<<1|1]);}
    void update(int rt, int l, int r, int pos, int x){
        if(mi[rt] == 1) return;
        if(l == r){
            mi[rt] = x; return;
        }
        if(pos <= mid) update(lson, pos, x);
        else update(rson, pos, x);
        up(rt);
    }
    int qry(int rt, int l, int r){
        if(mi[rt] == 1) return -1;
        if(l == r) return l;
        int t = -1;
        t = qry(lson);
        if(t != -1) return t;
        return qry(rson);
    }
}T[26];
char s[maxn];
int c[maxn];
int main()
{
    int n; cin>>n;
    scanf("%s", s);
    int mx = 0;
    for(int i = 0; i < n; ++i){
        int x = s[i]-'a';
        c[i] = T[x].qry(1, 1, n);
        mx = max(mx, c[i]);
        for(int j = 0; j < x; ++j) T[j].update(1, 1, n, c[i], 1);
    }
    cout<<mx<<endl;
    for(int i = 0; i < n; ++i) printf("%d ", c[i]);
}