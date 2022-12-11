#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  cin >> a;
  int n;
  cin >> n;
  set<string>bad;
  string c;
  for(int i = 0;i<n;i++){
    cin >> c;
    bad.insert(c);
  }
  int l = 0;
  int check;
  int len = 0,pos = 0;
  for(int i = 0;i<a.size();i++){
    c.clear();
    check = max(l,i-15);
    for(int j = i;j>=check;j--){
      c=a[j]+c;
      if(bad.count(c)){
        l=j+1;
        break;
      }
    }
    
    if(i-l+1>len)
      len=i-l+1,pos=l;
  }
  cout << len << " " << pos << "\n";
  return 0; 
}