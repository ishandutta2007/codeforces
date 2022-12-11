#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn  = 100;
int a[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int sum = 0;
        fors(i,0,n) cin>>a[i], sum+=a[i];
        sort(a,a+n);
        if(sum == 0){
            printf("NO\n"); continue;
        }else{
            printf("YES\n");
            if(sum > 0) reverse(a,a+n);
            fors(i,0,n){
                printf("%d", a[i]);
                if(i == n-1) printf("\n");
                else printf(" ");
            }
        }
    }
}