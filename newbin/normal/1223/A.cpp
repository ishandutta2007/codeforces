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
        int n; scanf("%d", &n);
        if(n == 2) printf("2\n");
        else if(n&1) printf("1\n");
        else printf("0\n");
    }
}