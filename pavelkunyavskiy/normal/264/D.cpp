#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

string s,t;

int cnt[3][3];

int l,r;

int get(char c){
    //cerr << (int)c << endl;
    if (c == 'R') return 0;
    if (c == 'B') return 1;
    if (c == 'G') return 2;
    assert(false);
}

void left(){
    cnt[get(t[l])][get(t[l+1])]--;
    l++;
}

void right(){
    cnt[get(t[r])][get(t[r+1])]++;
    r++;          
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    getline(cin,s);
    getline(cin,t);

    int n = s.size();
    int m = t.size();

    ll ans = 0;

    for (int i = 0; i < n; i++){
        while (r < m-1 && s[i] != t[r])
            right();
        if (!i || s[i] == s[i-1]) ans += r - l + 1;
        else ans += r - l + 1 - cnt[get(s[i])][get(s[i-1])];
        if (t[l] == s[i]){
            if (l == m - 1)
                break;
            left();
        }
        if (r < m-1) right();
//      cerr << ans << endl;    
    }

    cout << ans << endl;      
    return 0;
}