#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

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

ll gcd(ll A,ll B){
    return B ? A : gcd(B, A % B);
}

ll abs(ll x){
    return x > 0 ? x : -x;
}

string s;

int cnt = 0;

int main(){
    int x;cin >> x;
    cin >> s;
    if(s == "0"){
        cout << s << endl;
        return 0;
    }
    for(int i = 0;i<s.size();i++)
        cnt += int(s[i] == '0');
    cout << "1";
    for(;cnt;cnt--)
        cout << "0";
    cout << "\n";
    return 0;
}