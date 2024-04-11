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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    getline(cin,s);
    string t = "";
    for (int i = 0; i < s.size(); i++)
        if (string("AOYEUIaoyeui").find(s[i]) == string::npos){
            t += ".";
            if ('A' <= s[i] && s[i] <= 'Z')
                t += s[i] -'A' +'a';
            else
                t += s[i];
        }

    cout << t << endl;
  return 0;
}