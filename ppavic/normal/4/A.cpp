#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef pii pt;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int w;

int main(){
    scanf("%d",&w);
    if(w != 2 && w % 2 == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}