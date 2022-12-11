#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  set<int>q;
  int v;
  for(int i = 0;i<n;i++){
    cin >> v;
    if(q.count(v))q.erase(v);
    else q.insert(v);
  }
  if(q.empty())cout << "Agasa\n";
  else cout << "Conan\n";
  return 0;
}