#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
char s[maxn];
int check(int p){
    if(p < 1) return 0;
    for(int i = 0; i < 3; ++i) if(s[p+i] != 'a'+i) return 0;
    return 1;
}
int main(){
    int n, q; scanf("%d%d", &n, &q);
    scanf("%s", s+1);
    int ans = 0;
    fors(i,3,n+1) if(s[i] == 'c' && s[i-1] == 'b' && s[i-2] == 'a') ans++;
    while(q--){
        int p; char cmd[5]; scanf("%d%s", &p, cmd);
        fors(i,p-2,p+1) ans -= check(i);
        s[p] = cmd[0];
        fors(i,p-2,p+1) ans += check(i);
        printf("%d\n", ans);
    }
    return 0;
}