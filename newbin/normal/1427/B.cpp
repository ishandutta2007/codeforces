#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
#define P pair<int,int>
vector<P> p;
vector<int> tt;
int main()
{
    int T; cin>>T;
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s+1);
        s[n+1] = '*';
        p.clear();
        int cur = 1;
        int ans = 0;
        if(s[1]=='W') ans++;
        fors(i,2,n+2){
            if(s[i]=='W'){
                ans++;
                if(s[i-1] == 'W') ans++;
            }
            if(s[i] == s[i-1]) cur++;
            else{
                int op = (s[i-1] == 'W');
                p.pb(P(op, cur));
                cur = 1;
            }
        }
        tt.clear();
        if(k == 0){
            printf("%d\n", ans);
            continue;
        }
        for(int i = 1; i+1 < p.size(); ++i){
            if(p[i].first == 0) tt.pb(p[i].second);
        }
        if(p.size() == 1){
            if(p[0].first == 0){
                if(k >= p[0].second) ans = p[0].second*2-1;
                else ans = 2*k-1;
            }
            printf("%d\n", ans);
            continue;
        }
        //cout<<"ans:"<<ans<<endl;
        sort(tt.begin(), tt.end());
        fors(i,0,tt.size()){
           // cout<<"i:"<<i<<" t:"<<tt[i]<<" k:"<<k<<endl;
            if(k >= tt[i]){
                //cout<<"?"<<endl;
                k -= tt[i];
                ans += tt[i]*2 + 1;

            }else{
                ans += 2*k;
                k = 0; break;
            }
        }
        //cout<<"k:"<<k<<endl;
        if(k > 0){
            int len = p.size();
            //cout<<"p:"<<p[len-1].first<<endl;
            if(p[len-1].first == 0){
                //cout<<"t:"<<p[len-1].second<<endl;
                if(k >= p[len-1].second){
                    k -= p[len-1].second;
                    ans += 2*p[len-1].second;
                }else{
                    ans += 2*k;
                    k = 0;
                }
            }
        }
        if(k > 0){
            //cout<<"?"<<endl;
            if(p[0].first == 0){
                //cout<<"!:"<<ans<<endl;
                if(k >= p[0].second){

                    ans +=  p[0].second*2;
                    k -= p[0].second;
                }else{
                    ans += 2*k;
                    k = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
}
/*
1
1 0
L
-1
2
*/