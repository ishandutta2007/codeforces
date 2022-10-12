#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long sig=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    if(sig!=0){cout << "No\n";continue;}

    while(a.back()==0){a.pop_back();}
    if(a.empty()){cout << "Yes\n";continue;}
    n=a.size();
    
    if(a[0]==0){
      bool jud=true;
      for(int i=1;i<n;i++){
        if(a[i]!=0){jud=false;break;}
      }
      if(jud){cout << "Yes\n";}
      else{cout << "No\n";}
      continue;
    }

    long long cur=0;
    bool jud=true;
    for(int i=n-1;i>=0;i--){
      cur-=a[i];
      if(cur<0){jud=false;break;}
      if(cur==0 && i!=0){jud=false;break;}
    }

    if(jud){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}