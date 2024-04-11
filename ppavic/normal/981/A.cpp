#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair < int,int> pii;
typedef pair < double, double> pdd;
typedef pair < ll, ll > pll;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const ld EPS = 1e-10;
const ld PI = 3.1415926535897932384626433832795028;


int n, sol;
string s;

int main(){
    cin >> s;
    for(int i = 0;i<s.size();i++){
        for(int j = 1;j<=s.size();j++){
            if(i + j > s.size()) continue;
            string x = s.substr(i, j);
            string y = x;
            reverse(y.begin(),y.end());
            if(x != y){
                sol = max(sol, j);
            }
        }
    }
    cout << sol << endl;
    return 0;
}