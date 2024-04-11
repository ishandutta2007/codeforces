#include <bits/stdc++.h>
#define maxn 5050
#define pii pair<int,int>
#define debug 
typedef int num;
using namespace std;

int dp[maxn][maxn];
int pref[maxn][maxn];

int val[maxn][maxn];

inline int get(int a,int b){
    b++;
    return pref[b][b] - pref[a][b] - pref[b][a] + pref[a][a];
    int r = pref[b][b];
    if(a){
        r -= pref[b][a-1];
        r -= pref[a-1][b];
        r += pref[a-1][a-1];
    }
    debug("get %d %d %d\n",a,b,r);
    return r;
}

struct _1d1d {
    
    int sz;
    int opt[maxn];
    num ans[maxn];
    int k;
    pii D[maxn];
    int l,r;
    
    inline bool is_better(num a,num b){
        return a < b;
    }
    
    inline num eval(int pos,int nxt){
        return get(pos,nxt-1) + dp[k-1][nxt];
        assert(pos >= 0 && pos < sz && nxt > pos && nxt <= sz);
        int r = get(pos,nxt-1);
        if(nxt != sz)
            r += dp[k-1][nxt];
        debug("eva %d %d k %d = %d\n",pos,nxt,k,r);
        return r;
    }
    
    void solve(){
        l = 0, r = -1;
        //D.push_back(pii(sz,sz));
        //assert(r+1 >= l && r <= 3*sz);
        D[++r] = pii(sz,sz);
        for(int i=sz-1;i>=0;i--){
           // debug("i %d\n",i);
            while(r-l+1 >= 2 && D[l+1].first >= i)
                l++;
            //assert(r+1 >= l && r <= 3*sz);
            opt[i] = D[l].second;
            ans[i] = eval(i,opt[i]);
           // debug("i %d ans %d opt %d\n",i,ans[i],opt[i]);
            if(i == 0)
                continue;
            while(D[r].first < i && is_better(eval(D[r].first,i),eval(D[r].first,D[r].second)))
                r--;
            //assert(r+1 >= l && r <= 3*sz);
            //debug("oi\n");
            if(!is_better(eval(0,i),eval(0,D[r].second)))
                continue;
            //assert(r+1 >= l && r <= 3*sz);
            //debug("oiiiii\n");
            int lo = 0, hi = min(i-1,D[r].first);
            while(lo != hi){
                int mid = (lo+hi+1)/2;
                if(is_better(eval(mid,i),eval(mid,D[r].second)))
                    lo = mid;
                else
                    hi = mid-1;
            }
            
            if(lo == D[r].first)
                r--;
            //D.push_back(pii(lo,i));
            D[++r] = pii(lo,i);
            //assert(r+1 >= l && r <= 3*sz);
        }
    }
    
};

char ch;
inline void rd(int &x){
    x = 0;
    while((ch=getchar()) >= '0')
        x = 10*x+ch-'0';
}

int main() {
    
    int n,k;
    rd(n);
    rd(k);
   

  
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            val[i][j] = getchar()-'0';
            getchar();
        }
    assert(clock() < 2.0 * CLOCKS_PER_SEC);
    pref[1][1] = val[0][0];
    for(int j=1;j<n;j++)
        pref[1][j+1] = pref[1][j] + val[0][j];
    for(int i=1;i<n;i++){
        pref[i+1][1] = pref[i][1] + val[i][0];
        for(int j=1;j<n;j++)
            pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + val[i][j];
    }
    
    for(int i=0;i<n;i++)
        dp[1][i] = get(i,n-1);
   
    assert(clock() < 2.0 * CLOCKS_PER_SEC);
    for(int i=2;i<=k;i++){
        _1d1d a;
        a.sz = n;
        a.k = i;
        a.solve();
        for(int j=0;j<n;j++){
            dp[i][j] = a.ans[j];
            debug("%d ",dp[i][j]);
        }
        debug("\n");
    }
    
    printf("%d\n",dp[k][0]/2);
    
}