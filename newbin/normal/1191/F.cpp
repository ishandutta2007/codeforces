#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x & -x)
using namespace std;
const int maxn = 2e5 + 50;
ll cx[maxn], cy[maxn];
int nx, ny;
ll l[maxn], r[maxn];
int n;
ll a[maxn];
void add(int i, int x)
{
    while(i < maxn){
        a[i] += x;
        i += lowbit(i);
    }
}
ll query(int i)
{
    ll ans = 0;
    while(i){
        ans += a[i];
        i -= lowbit(i);
    }return ans;
}
struct node{
    ll x, y;
    bool operator < (const node & a){
        if(y != a.y) return y > a.y;
        return x < a.x;
    }
}e[maxn];
int main()
{
    memset(l,0x3f,sizeof l);
    memset(r,0,sizeof r);
    nx = ny = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%I64d%I64d",&e[i].x, &e[i].y);
        cx[++nx] = e[i].x;
        cy[++ny] = e[i].y;
    }
    cx[++nx] = 0x3f3f3f3f;
    sort(cx+1, cx+1+nx);
    nx = unique(cx+1, cx+1+nx) - cx - 1;
    sort(cy+1, cy+1+ny);
    ny = unique(cy+1, cy+1+ny) - cy - 1;
//    for(int i = 1; i <= n; ++i){
//        ll posx = lower_bound(cx+1, cx+nx+1, e[i].x) - cx;
//        ll posy = lower_bound(cy+1, cy+ny+1, e[i].y) - cy;
//        l[posy] = min(l[posy], posx);
//        r[posy] = max(r[posy], posx);
//    }
    ll ans = 0;
    sort(e+1, e+1+n);
    add(nx, 1);
    int pre = -1;
    for(int i = 1; i <= n; ++i){
        int posx = lower_bound(cx+1, cx+nx+1, e[i].x) - cx;
        if(query(posx) - query(posx-1) == 0) add(posx, 1);
        if(e[i].y != e[i+1].y){
            if(pre == -1){
                int posx = lower_bound(cx+1, cx+nx+1, e[i].x) - cx;
                ll L = query(posx);
                ll R = query(nx) - L;
                ans += L*R;
            }
            else{
                ll res = 0;
                ll A = query(nx);
                for(int j = pre; j <= i; ++j){
                    int posx = lower_bound(cx+1, cx+nx+1, e[j].x) - cx;
                    ll L = query(posx) - query(res);
                    ans += L*(A - query(posx));
                    res = posx;
                }
                pre = -1;
            }
        }
        else if(pre == -1) pre = i;
    }
    cout<<ans<<endl;
}