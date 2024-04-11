#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

#define FOR(i, n) for(unsigned i = 0; i < (n); ++i)
#define FORU(i, j, k) for(unsigned i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(unsigned i = (j); i >= (k); --i)

long mabs(long a){
  return a > 0 ? a : -a;
}

int main(int, char**){
  long a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a == c && b == d){
    cout << "0 0 0\n";
  }else{
    if(a == c || b == d){
      cout << "1 ";
    }else{
      cout << "2 ";
    }
    if((a+b-c-d) % 2 == 0){
      if(mabs(a-c) == mabs(b-d)){
        cout << "1 ";
      }else{
        cout << "2 ";
      }
    }else{
      cout << "0 ";
    }
    cout << max(mabs(a-c), mabs(b-d)) << endl;
  }
  return 0;
}