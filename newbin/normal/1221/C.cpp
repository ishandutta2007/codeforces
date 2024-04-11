#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--){
        int c, m , x;
        scanf("%d%d%d", &c, &m, &x);
        int ans = min(c, m);
        ans = min(ans, (c+m+x)/3);printf("%d\n", ans);
	}
}