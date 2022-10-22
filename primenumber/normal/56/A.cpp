#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  vector<string> alc = {{"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"}};
  int cnt = 0;
  REP(i,n){
    string str;
    cin>>str;
    for (auto n : alc) {
      if (n == str) ++cnt;
    }
    if (isdigit(str[0])) {
      if (atoi(str.c_str()) < 18) ++cnt;
    }
  }
  cout<<cnt<<endl;
  return 0;
}