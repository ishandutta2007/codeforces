#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair < ll,ll> pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

string s;
int sol = 0,frm;

int main(){
    cin >> frm >> s;
    if(s[3] >= '6') s[3] = '0';
    if(frm == 12){
        if((s[0] >= '2'|| (s[0] == '1' && s[1] > '2')) && s[1] != '0'){
            s[0] = '0';
        }
        else if(s[0] >= '2'){
            s[0] = '1';
        }

        else if(s[0] == '0' && s[1] == '0'){
            s[1] = '1';
        }
    }
    if(frm == 24){
        if(s[0] > '2' || (s[0] == '2' && s[1] > '3')){
            s[0] = '0';
        }
    }
    cout << s << endl;
}