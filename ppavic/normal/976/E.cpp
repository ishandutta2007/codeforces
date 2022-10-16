#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n,a,b;

vector < pair < ll, ll> > v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    b = min(n, b);
    for(int i = 0;i<n;i++){
        ll x,y; cin >> x >> y;
        v.PB(MP(x-y,y));
    }
    sort(v.rbegin(),v.rend());
    ll sm = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(i < b && v[i].X > 0LL)
            sm += v[i].X + v[i].Y,cnt++;
        else
            sm += v[i].Y;
    }
    ll bst = sm;
    for(int i = 0;i<n && b > 0;i++){
        ll hp = v[i].X + v[i].Y;
        ll pos = 0;
        for(int j = 0;j<a;j++)
            hp *= 2LL;
        if(i < cnt){
            pos = sm + hp - (v[i].X + v[i].Y);
        }
        else if(cnt < b){
            pos = sm + hp - v[i].Y;
        }
        else{
            pos = sm;
            if(cnt)
                pos -= v[cnt - 1].X;
            pos += hp - v[i].Y;
        }
        bst = max(bst, pos);
    }
    cout << bst << endl;
    return 0;
}