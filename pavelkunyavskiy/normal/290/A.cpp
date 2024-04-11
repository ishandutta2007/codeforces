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
#include <sstream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;

const string s[] = {
"Washington", "Adams", "Jefferson" , "Madison" , "Monroe" , "Adams" , "Jackson" , "Van Buren", "Harrison" , "Tyler" , "Polk" , "Taylor" , "Fillmore" , "Pierce"
 , "Buchanan" , "Lincoln", "Johnson" , "Grant" , "Hayes" , "Garfield" , "Arthur" , "Cleveland"
 , "Harrison" , "Cleveland" , "McKinley" , "Roosevelt" , "Taft" , "Wilson" , "Harding" , "Coolidge"
  , "Hoover" , "Roosevelt" , "Truman" , "Eisenhower" , "Kennedy" , "Johnson" , "Nixon" , "Ford"
   , "Carter" , "Reagan" , "Bush" , "Clinton"} ;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

//  cerr << sizeof(s)/sizeof(s[0]) << endl;
    int a;
    cin >> a;
    cout << s[a-1] << endl;
      
  TIMESTAMP(end);
  return 0;
}