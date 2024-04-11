#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

string s, t;
int n, k;

int main(){
    cin >> n >> k >>  t;
    s = t;
    int cur = 1;
    for(int i = 1;i<k;i++, cur++){
        int gud = 1;
        for(int j = cur;j<min(s.size(), cur + t.size());j++){
            if(t[j - cur] != s[j]) gud = 0;
        }
        if(!gud) {i--;continue;}
        for(int j = s.size();j < cur + t.size();j++){
            s.push_back(t[j - cur]);
        }
    }
    cout << s << endl;
    return 0;
}