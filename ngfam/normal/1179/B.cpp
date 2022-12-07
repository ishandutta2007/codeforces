#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> m;

  int curx = 1, cury = 1;

  auto print = [&]() {
    cout << curx << " " << cury << "\n";
  };



  print();
  if(n == 1 && m == 1) return 0;  
  
  for(int i = 1; i <= n; ++i) {
    int j = n - i + 1;
    //cout << "solving :" << i << " " << j << endl;
    if(j < i) break;
    if(i == j) {
     // if(i == 1 && m == 1) break;
      if(i != 1) curx = i, print();

      if(cury == 1) {
        cury = m;
        print();
      }

      for(int u = 2; u <= m; ++u) {
        int v = m - u + 1;
       // cout << "? " << u << " " << v << endl;
        if(u > v) break;
        if(u == v) {
          cury = u;
          print();
        }
        else {
          if(cury <= u) {
            cury = v;
            print();
            cury = u;
            print();
          }
          else {
            cury = u;
            print();
            cury = v;
            print();
          }
        }
      }
    }
    else {
      if(i > 1) if(curx <= n / 2) {
        curx = j;
        print();
      }
      else {
        curx = i;
        print();
      }

      curx = i ^ j ^ curx;
      cury = 1 ^ m ^ cury;
      print();

      int ok = -1;

      int smaller = 1, bigger = m;
      for(int t = 1; t < m; ++t) {
        if(cury == bigger && ok != 1) {
          ok = 0;
          curx = i ^ j ^ curx;
          cury = ++smaller;
          print();
          curx = i ^ j ^ curx;
          cury = --bigger;
          print();
        }
        else {
          ok = 1;
          curx = i ^ j ^ curx;
          cury = --bigger;
          print();
          curx = i ^ j ^ curx;
          cury = ++smaller;
          print();
        }
      }
    }
  }

  return 0;
}