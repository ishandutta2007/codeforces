#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

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

vector < llint > v;
llint n,x,l,c,a[N],k;
llint sol = 0;

int main(){
    scanf("%I64d%I64d%I64d",&n,&x,&k);
    for(int i = 0;i<n;i++){
        scanf("%I64d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    int l = 0,r = 0;
    for(int i = 0;i<n;i++){
        llint w1 = v[i] - v[i] % x - k * x;
        llint w2 = v[i] - v[i] % x - (k - 1) * x;
        w2 = min(w2, v[i]);
        while(l < n && v[l] <= w1)l++;
        while(r < n && v[r] <= w2)r++;
        sol += (llint)r - l;
    }

    printf("%I64d\n",sol);
}