#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define MP make_pair
#define PB push_back
#define INP scanf
#define OUT printf

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;
typedef pair < string,int> psi;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int n,k,m;
llint sol = 0;
string s;

int main() {
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i] != 'A') continue;
        int l = 0,r = 0;
        for(int j = 0;j<i;j++){
            if(s[j] == 'Q') l++;
        }
        for(int j = i+1;j<s.size();j++){
            if(s[j] == 'Q') r++;
        }
        sol += (llint)l * (llint)r;
    }
    cout << sol << endl;
}