#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  vector < int > a(3);
  for(int &x : a) cin >> x;
  sort(a.begin(), a.end());
  int d; cin >> d;
  
  cout << (a[1] - a[0] < d ? d - (a[1] - a[0]) : 0) + (a[2] - a[1] < d ? d - (a[2] - a[1]) : 0);

  return 0;
}