#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
priority_queue<ll, vector<ll> , greater<ll> > q;
int main()
{
	int T;cin>>T;
	while(T--){
        while(q.size()) q.pop();
        int n;cin>>n;
        int ok = 0;
        for(int i = 0; i < n; ++i){
            ll x; cin>>x;
            if(x < 2048)
            q.push(x);
            else if(x == 2048) ok = 1;
        }
        if(ok){
            printf("YES\n");
        }
        else{
            while(q.size() > 1){
                ll x = q.top(); q.pop();
                ll y = q.top(); q.pop();
                if(x == 2048 || y == 2048){
                    ok = 1; break;
                }
                if(x == y) q.push(2*x);
                else q.push(y);
            }
            if(q.size() && q.top() == 2048) ok = 1;
            if(ok){
                printf("YES\n");
            }
            else printf("NO\n");
        }
	}
}