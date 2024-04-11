#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
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

int n,a,b;
char s[N];

int main(){
    INP(n);
    INP2(a,b);
    scanf("%s",s);
    int st = a + b;
    for(int i = 0;i<n;i++){
        if(s[i] == '*') continue;
        int j = i;
        while(s[j] == '.') j++;
        int len = j - i;
        j--;
        if(a > b){
            a -= len / 2 + (len % 2);
            b -= len / 2;
        }
        else{
            a -= len / 2;
            b -= len / 2 + (len % 2);
        }
        i = j;
    }
    OUT(st - max(a, 0) - max(b, 0));
    return 0;
}