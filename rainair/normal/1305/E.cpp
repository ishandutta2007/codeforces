/*
 * Author: RainAir
 * Time: 2020-03-03 23:23:23
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;
int n,m;
int a[MAXN];
bool del[MAXN];

int main(){
    scanf("%d%d",&n,&m);int sm = 0;
    FOR(i,1,n) a[i] = i;int tot = 0;
    FOR(i,1,n){
        FOR(j,i+1,n){
            if(a[i]+a[j] <= n) sm++;
        }
    }
    if(m > sm){
        puts("-1");return 0;
    }
    m = sm-m;bool flag = false;
    ROF(i,n,3){
        if(!m) break;
        int mx = (i-1)/2;
        if(mx <= m){
            m -= mx;a[i] = 1e9-tot;tot += 100000;continue;
        }
        int l = a[i],r = a[i-1]+a[i-2]+233,ans = a[i];
//        DEBUG(m);
        while(l <= r){
            int mid = (l + r) >> 1;int tmp = 0;
            FOR(j,1,i-1){
  //              if(mid == 7) DEBUG(j),DEBUG(mid-j);
                if(mid-j > j && mid-j <= i-1) tmp++;
            }
//            DEBUG(tmp);
            if(mx-tmp <= m){
                ans = mid;l = mid+1;
            }
            else r = mid-1;
        }
        a[i] = ans;m = 0;break;
        if(!m) break;
    }
    if(m){
        puts("-1");return 0;
    }
    FOR(i,1,n) printf("%d ",a[i]);puts("");
/*    int chk = 0;
    FOR(i,1,n){
        FOR(j,i+1,n){
            FOR(k,j+1,n){
                if(a[i]+a[j] == a[k]) chk++;
            }
        }
    }*/
//    DEBUG(chk);
    return 0;
}