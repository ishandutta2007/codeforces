#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
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

ll n,m,k;

int main(){
    cin >> n >> m >> k;
    if(k < n){
        cout << k + 1 << " " << 1 << endl;
    }
    else{
        k -= n;
        m--;
        cout << n - (k / m) << " ";
        if((k / m) % 2 == 0){
            cout << k % m + 2 << endl;
        }
        else{
            cout << m - (k % m) + 1 << endl;
        }
    }
    return 0;
}