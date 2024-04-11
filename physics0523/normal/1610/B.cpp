#include<bits/stdc++.h>

using namespace std;

bool jud(vector<int> &a,int x){
  int p=0,q=a.size()-1;
  while(p<q){
    //cerr << x << ' ' << p << ' ' << q << '\n';
    if(a[p]!=a[q]){
      if(a[p]==x){p++;continue;}
      else if(a[q]==x){q--;continue;}
      else{return false;}
    }
    p++;q--;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int p=0,q=n-1;
    vector<int> cd;
    while(p<q){
      if(a[p]!=a[q]){cd.push_back(a[p]);cd.push_back(a[q]);break;}
      p++;q--;
    }
    if(cd.size()==0){cout << "YES\n";continue;}
    if(jud(a,cd[0])){cout << "YES\n";}
    else if(jud(a,cd[1])){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}