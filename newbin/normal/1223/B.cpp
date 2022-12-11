#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 105;
char s[maxn], t[maxn];
int main()
{
    int q; cin>>q;
    while(q--){
        scanf("%s%s", s, t);
        int ok = 0;
        int n = strlen(s);
        for(int i = 0; i < n; ++i) for(int j = 0;j<n;++j) if(s[i] == t[j]) ok = 1;
        if(ok) printf("YES\n"); else printf("NO\n");
    }
}