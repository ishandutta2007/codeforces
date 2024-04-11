#include <bits/stdc++.h>
#define maxn 100100
#define pii pair<int,int>
#define debug 
typedef long long num;
using namespace std;

long long A[maxn];
long long B[maxn];

struct _1d1d {
    
    int sz;
    int opt[maxn];
    num ans[maxn];
    
    bool is_better(num a,num b){
        return a < b;
    }
    
    num eval(int pos,int nxt){
        if(pos == sz-1)
            return 0;
        if(nxt == sz)
            return 2e18;
        return B[pos] * A[nxt] + ans[nxt];
    }
    
    void solve(){
        deque<pii> D;
        D.push_back(pii(sz,sz));
        for(int i=sz-1;i>=0;i--){
            debug("i %d\n",i);
            for(int j=0;j<D.size();j++)
                debug("%d %d\n",D[j].first,D[j].second);
            while(D.size() >= 2 && D[1].first >= i)
                D.pop_front();
            opt[i] = D[0].second;
            ans[i] = eval(i,opt[i]);
            debug("dp[%d] = %lld opt %d\n",i,ans[i],opt[i]);//if(i == 0) return;
            while(D.back().first <= i && is_better(eval(D.back().first,i),eval(D.back().first,D.back().second)))
                D.pop_back();
            debug("sz %d\n",D.size());
            if(!is_better(eval(0,i),eval(0,D.back().second)))
                continue;
            int lo = 0, hi = min(i-1,D.back().first);
            while(lo != hi){
                int mid = (lo+hi+1)/2;
                if(is_better(eval(mid,i),eval(mid,D.back().second)))
                    lo = mid;
                else
                    hi = mid-1;
            }
            if(lo == D.back().first)
                D.pop_back();
            D.push_back(pii(lo,i));
        }
    }
    
};

int main() {
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",A+i);
    for(int i=0;i<n;i++)
        scanf("%lld",B+i);

    _1d1d a;
    a.sz = n;
    a.solve();
    
    printf("%lld\n",a.ans[0]);
    
}