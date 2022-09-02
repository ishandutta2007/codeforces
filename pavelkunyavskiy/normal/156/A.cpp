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

string s,t;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  getline(cin,s);
  getline(cin,t);

  string temp = "";

  for (int i = 0; i < 2010; i++)
     temp += char(1);

  s = temp+s+temp;

//  cerr << s <<"\n"<<t<<endl;

  int ans = 1<<30;

  for (int i = 0; i+t.size() <= (int)s.size(); i++){
    int cnt = 0;
    for (int j = 0; j < (int)t.size(); j++)
        cnt += (t[j] != s[i+j]);
    ans = min(ans,cnt);
  }

  cout << ans << endl; 
  return 0;
}