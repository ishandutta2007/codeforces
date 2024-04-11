#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <deque>

#define X first
#define Y second
#define INP(x) scanf("%d",&(x))
#define OUT(x) printf("%d\n",(x))
#define INP2(x,y) scanf("%d%d",&(x),&(y))
#define OUT2(x,y) printf("%d %d\n",(x),(y))
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef vector < int > vi;
typedef pii pt;
typedef pair < ll,ll> pll;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 31337;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

unordered_map < ll , int > mp;
vector < pair < int , ll > > v;
ll a[N];
int n;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i = 0;i<n;i++){
        if(mp[a[i]] != 0){
            mp[a[i]] = 0;
            a[i] *= 2LL;
            while(mp[a[i]] != 0){
                mp[a[i]] = 0;
                a[i] *= 2LL;
            }
            mp[a[i]] = i + 1;
        }
        else{
            mp[a[i]] = i + 1;
        }
    }
    for(auto it = mp.begin();it != mp.end();it++){
        if(it->second == 0) continue;
        v.PB(MP(it->second,it->first));
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i = 0;i<v.size();i++)
        printf("%I64d ",v[i].Y);
    printf("\n");
    return 0;
}