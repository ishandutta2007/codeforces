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

const int N = 250;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n, p[N];
string s[N];

int main(){
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> p[i];
    getline(cin,s[0]);
    for(int i = 0;i<n;i++){
        getline(cin, s[i]);
    }
    for(int i = 0;i<n;i++){
        int cnt = 0,mi = 0,lst = 0;
        for(int j = 0;s[i][j] != '\0';j++){
            cnt += int(s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u' || s[i][j] == 'y');
            lst += int(s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u' || s[i][j] == 'y');
            if(s[i][j + 1] == ' ' || s[i][j + 1] == '\0'){
                mi += int(lst > 0);
                lst = 0;
            }
        }
        if(cnt != p[i] || p[i] < mi){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}