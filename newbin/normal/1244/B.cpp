#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
string s;
int main()
{
    int T; cin>>T;
    while(T--){
        int n; cin>>n>>s;
        int ans = n;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1')  ans = max(ans, 2*max(i+1,n-i));
        }
        cout<<ans<<endl;
    }
}