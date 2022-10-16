#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pii pt;
typedef pair <ll, ll> pll;
typedef vector < int > v;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

string s;
int a,b,c,n,i;

int main(){
    cin >> s;
    n = s.size();
    while(i < n && s[i] == 'a'){
        i++,a++;
    }
    while(i < n && s[i] == 'b'){
        i++,b++;
    }
    while(i < n && s[i] == 'c'){
        i++,c++;
    }
    if(!a || !b || !c) printf("NO\n");
    else if(a + b + c != n) printf("NO\n");
    else if(a != c && b != c) printf("NO\n");
    else printf("YES\n");
    return 0;
}