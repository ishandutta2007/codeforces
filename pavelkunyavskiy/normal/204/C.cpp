#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

long double ans;

string s,t;

long long val[2][26];



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    getline(cin,s);
    getline(cin,s);
    getline(cin,t);

    int n = s.size();

    assert(n == (int)t.size());

    for (int i = n-1; i >= 0; i--){
        ans += val[1][s[i]-'A'] * 1LL * (i+1);
        val[0][s[i]-'A'] += n - i;
        ans += val[0][t[i]-'A'] * 1LL * (i+1);
        val[1][t[i]-'A'] += n - i;
    }

    long double total = 0;

    for (int i = 1; i <= n; i++)
        total += (n - i + 1) * 1LL * (n - i + 1);


    cout.precision(20);

    cout << fixed << ((ld)ans)/((ld)total) << endl;


      
  return 0;
}