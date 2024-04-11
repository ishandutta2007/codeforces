#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e3 + 50;
char s[maxn];
int vis[30];
int main()
{
    int T;cin>>T;
    while(T--){
        scanf("%s", s);
        memset(vis, 0, sizeof vis);
        int p = 0;
        int n = strlen(s);
        while(p < n){
            int cnt = 1;
            while(p+1 < n && s[p+1] == s[p]) cnt++, p++;
            int x = s[p] - 'a';
            if(cnt&1) vis[x] = 1;
            p++;
        }
        for(int i = 0; i < 26; ++i) if(vis[i]) printf("%c",i+'a');printf("\n");
    }
}