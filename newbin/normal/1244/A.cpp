#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int main()
{
    int T; cin>>T;
    while(T--){
        int a, b, c, d, k; cin>>a>>b>>c>>d>>k;
        int t1 = (a+c-1)/c;
        int t2 = (b+d-1)/d;
        if(t1 + t2 > k) printf("-1\n");
        else printf("%d %d\n", t1, t2);
    }
}