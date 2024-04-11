
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#define _CRT_SECURE_NO_WARNINGS

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

ll val[N], node[N],q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for(int i = 0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1 || t == 2){
            ll x ,k;
            cin >> x >> k;
            ll lv = 0;
            while((1LL << lv) <= x) lv++;
            lv--;
            ll len = (1LL << lv);
            k %= len;
            k += len;
            k %= len;
            if(t == 1)val[lv] = (val[lv] + k ) % len;
            else      node[lv] = (node[lv] + k ) % len;
        }
        else{
            ll x;
            cin >> x;
            ll lv = 0;
            while((1LL << lv) <= x) lv++;
            lv--;
            int st = 1;
            while(lv >= 0){
                ll len = (1LL << lv);
                ll nw = x;
                nw -= len;
                if(!st)
                    nw = (nw - val[lv] + len) % len;
                nw += len;
                cout << nw << " ";
                if(st){
                    x -= len;
                    x = (x + val[lv] + len) % len;
                    x += len;

                }
                x -= len;
                x = (x + node[lv]) % len;
                x += len;
                lv--,x>>=1LL;
                st = 0;
            }
            cout << "\n";
        }
    }
    return 0;
}