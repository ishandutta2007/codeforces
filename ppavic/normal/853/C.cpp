
 #include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int llint;

const int OFF = 1 << 21;
const int N = 2e5 + 500;

vector < int > tour[3 * OFF];
int n,x,l,r,u,d,q;

llint query(int i,int a,int b,int lo,int hi,int x,int sm){
    if(lo > hi) return 0;
    if(lo <= a && b <= hi){
        if(sm) return (llint)(tour[i].size() - (upper_bound(tour[i].begin(),tour[i].end(),x) - tour[i].begin()));
        return  llint(lower_bound(tour[i].begin(),tour[i].end(),x) - tour[i].begin());
    }
    if(a > hi || b < lo) return 0;
    return query(2 * i, a , (a+b)/2,lo,hi ,x , sm) + query(2 * i + 1 , (a+b+2)/2, b , lo, hi, x , sm);
}

int main(){
    scanf("%d %d",&n,&q);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        int j = i + OFF;
        for(; j ; j >>=1){
            tour[j].push_back(x);
        }
    }
    for(int i = 0;i < 2 * OFF; i++)
        sort(tour[i].begin(),tour[i].end());
    for(int i = 0;i<q;i++){
        scanf("%d%d%d%d",&l,&d,&r,&u);l--;r--;
        llint n1 = query( 1 , 0 , OFF - 1 ,0 , l - 1, u ,1 );
        llint n2 = query( 1 , 0 , OFF - 1 ,r + 1 , n - 1 ,u ,1 );
        llint m1 = query( 1 , 0 , OFF - 1 ,0 , l - 1, d ,0 );
        llint m2 = query( 1 , 0 , OFF - 1 ,r + 1 , n - 1 ,d ,0 );
        llint a1 = query( 1 , 0 , OFF - 1, 0 , n - 1 , u, 1);
        llint a2 = query( 1 , 0 , OFF - 1, 0 , n - 1 , d, 0);
        llint b1 = (llint)l;
        llint b2 = (llint)(n - r - 1);
        llint all = ((llint)n) * ((llint)n - 1) / 2LL;
        all += (n1 * (n1 - 1LL) + n2 * (n2 - 1LL) + m1 * (m1 -1LL) + m2 * (m2 - 1LL)) / 2LL;
        all -= (b1 * (b1 - 1LL) + b2 * (b2 - 1LL) + a1 * (a1 - 1LL) + a2 * (a2 - 1LL)) / 2LL;
        printf("%I64d\n", all);
    }
}