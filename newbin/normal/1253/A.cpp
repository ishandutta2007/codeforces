#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn], b[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        int ok = 1;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]); b[i] -= a[i];
            if(b[i] < 0) ok = 0;
        }
        if(!ok){
            printf("NO\n"); continue;
        }
        b[0] = b[n+1] = 0;
        int cnt = 0;
        for(int i = 1; i <= n+1; ++i){
            if(b[i] && b[i-1] && b[i] != b[i-1]){
                cnt = 2;break;
            }
            if(!b[i]){
                if(b[i-1]) cnt++;
            }
        }
        //cout<<"cnt:"<<cnt<<endl;
        if(cnt > 1) printf("NO\n");
        else printf("YES\n");
    }
}