#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;


int n, m, x = 1, y = 1, j;
int cnt[N];
string sol, sol2;

bool ask(int x,int y, int z){
    if(z == 0){
        cout << "? " << x << " " << y << " " << n << " " << n << " "  << endl;
        string res;cin >> res;
        if(res[0] == 'Y')return 1;
        return 0;
    }
    if(z == 1){
        cout << "? " << 1 << " " << 1 << " " << x << " " << y << " " << endl;
        string res;cin >> res;
        if(res[0] == 'Y')return 1;
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n - x + n - y - 1 >= n - 1){
        //printf("CURRENTLY AT %d %d\n", x, y);
        if(x + 1 <= n && ask(x + 1, y, 0)){
            x++;
            sol.PB('D');
        }
        else{
            y++;
            sol.PB('R');
        }
    }
    x = n, y = n;
    while(x - 1 + y - 1 - 1 >= n - 1){
        //printf("CURRENTLY AT %d %d\n", x, y);
        if(y - 1 >= 1 && ask(x, y - 1, 1)){
            y--;
            sol2.PB('R');
        }
        else{
            x--;
            sol2.PB('D');
        }
    }
    reverse(sol2.begin(), sol2.end());
    sol += sol2;
    cout << "! " << sol << endl;
    return 0;
}