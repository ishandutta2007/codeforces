#include<bits/stdc++.h>

using namespace std;

bool jud(vector<long long> a,vector<long long> b){
  long long pa=0,pb=25;
  while(pa<26 && pb>=0){
    while(pa<26 && a[pa]==0){pa++;}
    while(pb>=0 && b[pb]==0){pb--;}
    if(pa==26 || pb==-1){break;}

    if(pa<pb){return true;}
    if(pa>pb){return false;}
    long long del=min(a[pa],b[pb]);
    a[pa]-=del;
    b[pb]-=del;
  }

  if(pb>=0){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int q;
    cin >> q;
    vector<long long> a(26,0),b(26,0);
    a[0]++;b[0]++;
    while(q>0){
      q--;
      int typ;
      long long ce;
      string s;
      cin >> typ >> ce >> s;
      for(auto &nx : s){
        if(typ==1){a[nx-'a']+=ce;}
        else{b[nx-'a']+=ce;}
      }
      if(jud(a,b)){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}