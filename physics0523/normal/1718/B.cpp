#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<long long> fib;
  fib.push_back(1);
  fib.push_back(2);
  while(fib.back()<=1000000007){
    int sz=fib.size();
    fib.push_back(fib[sz-1]+fib[sz-2]);
  }

  map<long long,int> mp;
  long long sig=0;
  for(int i=0;i<fib.size();i++){
    sig+=fib[i];
    mp[sig]=i+1;
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    bool allfl=false;

    for(int fix=0;fix<n;fix++){
      long long sig=0;
      priority_queue<pl> pq;
      for(int i=0;i<n;i++){
        long long v=a[i];
        if(fix==i){v--;}
        if(v>0){
          pq.push({v,1000000*n+i});
          sig+=v;
        }
      }

      if(sig==0){allfl=true;break;}
      if(mp.find(sig)==mp.end()){continue;}
      int fsz=mp[sig];
      bool jud=true;
      int prev=-1;
      for(int i=fsz-1;i>=0;i--){
        if(pq.empty()){jud=false;break;}

        pl od=pq.top();pq.pop();
        if(i==0 && od.second%n==fix){jud=false;break;}
        // cout << od.first << " " << od.second << "\n";
        if(prev==od.second%n){jud=false;break;}
        prev=(od.second%n);
        if(od.first<fib[i]){jud=false;break;}
        od.first-=fib[i];
        od.second=i*n+(od.second%n);
        if(od.first!=0){pq.push(od);}
      }
      if(!pq.empty()){jud=false;continue;}
      if(jud){allfl=true;break;}
    }

    if(allfl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}