#include <bits/stdc++.h>

using namespace std;

map<string,string>name;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  string a,b;
  while(n--){
    cin >> a >> b;
    b+=";";
    name[b]=a;
  }
  while(m--){
    cin >> a >> b;
    cout << a << " " << b << " " << "#" << name[b] << "\n";
  }
  return 0;
}