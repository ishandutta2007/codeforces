#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int pre[2];
const int maxn = 3e5 + 50;
char s[maxn];
int main()
{
	int n; cin>>n;
	scanf("%s", s+1);
	ll ans = 0;
	ll cnt = 0;
	for(int i = 2; i <= n; ++i){
        int x = s[i]-'A';
        if(s[i] == s[i-1]){
            cnt++;
            ans += cnt + pre[x];
            int t = pre[x^1] - pre[x]-1;
            if(t > 0) ans += t;
        }
        else{
            pre[x^1] = i-1;
            ans += pre[x];
            cnt = 0;
        }
	}
	cout<<ans<<endl;
}