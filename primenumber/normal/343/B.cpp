#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int main()
{
  stack<char> stk;
  string str;
  cin >> str;
  for(int i = 0;i < str.size();++i) {
    if(stk.empty() || stk.top() != str[i])
      stk.push(str[i]);
    else
      stk.pop();
  }
  if(stk.empty())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}