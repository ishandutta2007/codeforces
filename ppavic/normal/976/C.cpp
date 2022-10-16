#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef pair < pii,int> ppi;
typedef pair < int,ppi> pip;
typedef vector < int > vi;
typedef pii pt;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

vector < ppi > v;

int n;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int l,r;scanf("%d%d",&l,&r);
        v.PB(MP(MP(l,-r), i + 1));
    }
    sort(v.begin(),v.end());
    int mks = -1;
    for(int i = 0;i<v.size();i++){
        v[i].X.Y *= -1;
        if(mks != -1 && v[mks].X.Y >= v[i].X.Y){
            printf("%d %d\n", v[i].Y, v[mks].Y);
            return 0;
        }
        else{
            mks = i;
        }
    }
    printf("-1 -1\n");
    return 0;
}