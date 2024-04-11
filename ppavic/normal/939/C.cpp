#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef pair < double,double> pt;
typedef vector < int > vi;

const int N = 2e5 + 300;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int a[N],n,l,r,pref[N];

int get(int l,int r){
    if(!l) return pref[r];
    return pref[r] - pref[l - 1];
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        pref[i] = a[i];
        if(i)
            pref[i] += pref[i - 1];
    }
    for(int i = n;i<N;i++)
        pref[i] = pref[i - 1] + a[i % n];
    scanf("%d%d",&l,&r);r--;
    int mks = 0,tm = 0;
    for(int i = 0;i<n;i++){
        int cur = l - i;
        if(cur <= 0) cur += n;
        if(mks < get(i, i + r - l)){
            mks = get(i, i + r  - l);
            tm = cur;
        }
        if(mks == get(i,i + r - l))
            tm = min(tm,cur);
    }
    printf("%d\n",tm);
    return 0;
}