#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  int k;
  cin >> a >> k;
  int l,j;
  for(int i = 0;i<a.size();i++){
    l = a[i];
    j = i;
    for(int x = i+1;x<a.size();x++){
      if(x-i>k)continue;
      if(a[x]>l)
        l = a[x],j = x;
    }
    for(int x = j-1;x>=i;x--)
      swap(a[x],a[x+1]);
    k -= j-i;
  }
  cout << a << "\n";
  return 0;
}