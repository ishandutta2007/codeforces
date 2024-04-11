#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 500;

int n,sol = 0;

int main(){
    scanf("%d",&n);
    while(n > 0){
        sol += n;
        n -= 2;
    }
    printf("%d\n",sol);
}