#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MDO = 1e9 + 7;

int n,x,y;
string s;

int main(){
    cin >> n >> s;
    for(int i = 0;i<n;i++){
        if(s[i] == 'L') x++;
        if(s[i] == 'R') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
    }
    printf("%d\n",n - abs(x) - abs(y));
    return 0;
}