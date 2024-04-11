#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int> pii;
typedef pair < int, pii> pip;
typedef pair < pii, int> ppi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

string s;
int cnt1, cnt2;

int main(){
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '-') cnt1++;
        else cnt2++;
    }
    if(cnt2 != 0 && cnt1 % cnt2) printf("NO\n");
    else printf("YES\n");
}