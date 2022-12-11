#include <bits/stdc++.h>

using namespace std;

set<char>C;

void ini(){
  for(char x ='a';x<='z';x++)
    C.insert(x);
}

int main(){
  ini();
  int n;
  cin >> n;
  char v;
  string a;
  int ans = 0;
  for(int i = 0;i<n;i++){
    cin >> v >> a;
    if(i==n-1)break;
    if(v=='?'){
      if(C.size()==1)ans++;
      if(C.count(a[0]))C.erase(a[0]);
      continue;
    }
    if(v=='.'){
      for(char x : a)
        if(C.count(x))C.erase(x);
      continue;
    }
    if(C.size()==1)
      ans++;
    if(v=='!'){
      set<char>cur;
      for(char x : a)
        cur.insert(x);
      for(char x = 'a';x<='z';x++)
        if(!cur.count(x))
          if(C.count(x))C.erase(x);
    }
  }
  cout << ans << "\n";
  return 0;
}