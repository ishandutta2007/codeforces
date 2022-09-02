#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <sstream>
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

vector<string> cur;

int n;
string s;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  getline(cin,s);

  sscanf(s.data(),"%d",&n);

  for (int i = 0; i < n; i++){
    cin >> s;
    if (s == "pwd"){
        cout <<"/";
        for (int i = 0; i < (int)cur.size(); i++)
            cout << cur[i] <<"/";
        cout << endl;
        continue;
    }
    cin >> s;
    if (s[0] == '/')
        cur.clear();
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == '/')
            s[i] = ' ';
    stringstream str(s);
    string t;

    for (;str >> t;){
        if (t == ".."){
            if (cur.size())
                cur.pop_back();
        }
        else
            cur.pb(t);
    }        

  }


  return 0;
}