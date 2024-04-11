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

int f[N],n;

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%d",f+i);
    for(int i = 1;i<=n;i++){
        int j = f[i];
        for(int k = 1;k<=n;k++){
            if(f[i] == j && f[j] == k && f[k] == i){
                printf("yes\n");
                return 0;
            }

        }
    }
    printf("no\n");
    return 0;
}