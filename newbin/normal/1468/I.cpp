#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
ll x1, y1, y2;
void add(ll x, ll y){
    if(x==0){
        y2 = __gcd(y2, y); return;
    }
    if(x < 0) x = -x, y = -y;
    if(x1 == 0) x1 = x, y1 = y;
    else {
        while(1){
            y -= x/x1*y1;
            x -= x/x1*x1;
            if(x == 0) break;
            swap(x, x1); swap(y, y1);
        }
        if(y < 0) y = -y;
        y2 = __gcd(y, y2);
        if(y2) y1 %= y2;
    }
}
int main()
{
    int n; cin>>n;
    x1 = y1 = y2 = 0;
    ll x, y;
    cin>>x>>y; add(x, y);
    cin>>x>>y; add(x, y);
    ll tot = x1*y2;
    if(n != tot) puts("NO");
    else {
        puts("YES");
        fors(i,0,x1) fors(j,0,y2) printf("%d %d\n", i, j);
    }
	return 0;
}