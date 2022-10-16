#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < int, pii> pip;
typedef pair < pii, int> ppi;
typedef pii pt;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

unordered_map < ll, ll> r, s;
map < pair < ll , ll > , ll > ch;

int n;
ll w,h,c, sm;

ll gcd(ll A,ll B){
    return B ? gcd(B, A % B) : A;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> w >> h >> c;
        r[w] += c;
        s[h] += c;
        ch[MP(w, h)] = c;
        sm += c;
    }
    ll c1 = r.begin()->second, c2 = s.begin()->second;
    for(auto it = r.begin();it != r.end();it++){
        c1 = gcd(it->second, c1);
    }
    for(auto it = s.begin();it != s.end();it++){
        c2 = gcd(it->second, c2);
    }
    ll sol = 0;
    for(ll i = 1;i*i<=c1;i++){
        if(c1 % i) continue;
        if(c2 % (sm / i) == 0) {
            sol++;
            if(sol == 1){
                for(auto it = ch.begin();it!=ch.end();it++){
                    if((r[it->first.first] / i) * (s[it->first.second] / (sm / i)) != it->second){
                        sol--;
                        printf("0\n");
                        return 0;
                        break;
                    }
                }
            }
        }
        if(c2 % (sm / (c1 / i)) == 0 && i * i != c1) {
            sol++;
            if(sol == 1){
                for(auto it = ch.begin();it!=ch.end();it++){
                    if((r[it->first.first] / (c1 / i)) * (s[it->first.second] / (sm / (c1 / i))) != it->second){
                        sol--;
                        printf("0\n");
                        return 0;
                        break;
                    }
                }
            }
        }
    }
    cout << sol << endl;
    return 0;
}