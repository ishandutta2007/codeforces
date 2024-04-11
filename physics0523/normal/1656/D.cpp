#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  long long v=2;
  set<long long> st;
  while(1){
    if(v>2e18){break;}
    st.insert(v);
    v*=2;
  }

  while(t>0){
    t--;
    long long v;
    cin >> v;
    if(st.find(v)!=st.end()){
      cout << "-1\n";
      continue;
    }
    bool fail=true;
    for(long long k=2;;k*=2){
      long long sub=llsankaku(k);
      if((v-sub)<0){break;}
      if((v-sub)%k==0){
        fail=false;
        cout << k << '\n';
        break;
      }
    }
    if(fail){
      long long k=v;
      while(k%2==0){k/=2;}
      long long sub=llsankaku(k);
      if((v-sub)>=0 && (v-sub)%k==0){
        fail=false;
        cout << k << '\n';
      }
      else{
        cout << "-1\n";
      }
    }
  }
  return 0;
}