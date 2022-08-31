//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo              0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd
using namespace std;

void rotate(char x[4][4]) {
    char a = x[0][0], b = x[0][1], c = x[1][0], d = x[1][1];
    x[0][0] = c;
    x[0][1] = a;
    x[1][0] = d;
    x[1][1] = b;
}

string ans(char a[4][4]) {
    string ret;
    for (int i=0; i < 2; i++) for (int j=0; j < 2; j++) ret += a[i][j];
    return ret;
}
string solve(char a[4][4]) {
    string ret = ans(a);
    rotate(a);
    ret = min( ret, ans(a) );
    rotate(a);
    ret = min( ret, ans(a) );
    rotate(a);
    ret = min( ret, ans(a) );
    return ret;
}
char a[4][4];
int main(){
    int n;
    scanf("%d", &n);
    set<string> z;
    for (int i=0; i < n; i++) {
        for (int j=0; j < 3; j++)
            scanf("%s", a[j]);
        string zz = solve(a);
        //cout << zz << endl;
        z.insert( zz );
    }
    cout << z.size() << endl;
    return 0;
}