#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n,a[N],sol = 360;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = 0;j<n;j++){
            sum += a[(i+j) % n];
            sol = min(sol, abs(2 * sum - 360));
        }
    }
    printf("%d\n",sol);
}