#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
char s[105];
int a[105];
int main()
{
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        int x[2]; x[0] = x[1] = 0;
        for(int i = 0; i < n; ++i){
            scanf("%s", s);
            int len = strlen(s);
            a[i] = len/2;
            for(int j = 0; j < len; ++j) x[s[j]-'0']++;
        }
        int d = x[0]/2 + x[1]/2;
        //cout<<"d:"<<x[0]<<" "<<x[1]<<endl;
        sort(a,a+n);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(d >= a[i]){
                d -= a[i]; ans++;
            }else break;
        }printf("%d\n", ans);
    }
}