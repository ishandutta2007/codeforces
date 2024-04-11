#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector < string > v;
string s,x;
int n,gud = 0;

int main(){
    cin >> s >> n;
    for(int i = 0;i<n;i++){
        cin >> x;
        v.push_back(x);
        if(x == s) gud = 1;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(v[i][1] == s[0] && v[j][0] == s[1]) gud = 1;
        }
    }
    if(gud){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}