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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll a[N],n,k,sol,cnt;

int main(){
    scanf("%I64d%I64d",&n,&k);
    for(int i = 0;i<k;i++){
        scanf("%I64d",a+i);
        if(n / a[i] * a[i] > sol){
            sol = n / a[i] * a[i];
            cnt = i;
        }
    }
    printf("%I64d %I64d\n",cnt + 1,n / a[cnt]);
    return 0;
}