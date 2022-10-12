#include<bits/stdc++.h>

using namespace std;

int n;
multiset<long long> a,b;
vector<long long> ra,rb;
bool solve(long long x){
  multiset<long long> ma=a,mb=b;
  ra.clear();rb.clear();

  // diff == x
  while(!ma.empty()){
    auto ait=ma.end();ait--;
    auto bit=mb.end();bit--;
    if((*ait)<x && (*bit)<x){break;}
    if((*ait)>(*bit)){
      bit=mb.find((*ait)-x);
      if(bit==mb.end()){return false;}

      ra.push_back((*ait));
      rb.push_back((*bit));
      ma.erase(ait);
      mb.erase(bit);
    }
    else{
      ait=ma.find((*bit)-x);
      if(ait==ma.end()){return false;}

      ra.push_back((*ait));
      rb.push_back((*bit));
      ma.erase(ait);
      mb.erase(bit);
    }
  }

  // sum == x
  while(!ma.empty()){
    auto ait=ma.begin();
    auto bit=mb.find(x-(*ait));
    if(bit==mb.end()){return false;}

    ra.push_back((*ait));
    rb.push_back((*bit));
    ma.erase(ait);
    mb.erase(bit);
  }

  return true;
}

bool restore(long long x){
  long long p0=0,p1=x;
  vector<long long> pos;

  for(int i=0;i<n;i++){
    if(ra[i]+rb[i]==x){
      pos.push_back(ra[i]);
    }
    else if(ra[i]<rb[i]){
      pos.push_back(-ra[i]);
    }
    else{
      pos.push_back(x+rb[i]);
    }
  }

  long long trans=0;
  for(auto &nx : pos){
    trans=max(trans,-nx);
  }

  p0+=trans;
  if(p0>2000000000){return false;}
  p1+=trans;
  if(p1>2000000000){return false;}

  for(auto &nx : pos){
    nx+=trans;
    if(nx>2000000000){return false;}
  }

  cout << "YES\n";
  for(int i=0;i<n;i++){
    if(i){cout << " ";}
    cout << pos[i];
  }cout << "\n";
  cout << p0 << " " << p1 << "\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    a.clear();b.clear();
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      a.insert(v);
    }
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      b.insert(v);
    }

    bool ng=true;
    long long atg=(*a.begin());
    for(auto &btg : b){
      long long magic=(atg+btg);
      if(solve(magic)){
        if(restore(magic)){
          ng=false;break;
        }
      }

      magic=abs(atg-btg);
      if(solve(magic)){
        if(restore(magic)){
          ng=false;break;
        }
      }
    }
    if(ng){cout << "NO\n";}
  }
  return 0;
}