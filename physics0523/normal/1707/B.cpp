#include<bits/stdc++.h>

using namespace std;

vector<long long> f(vector<long long> &a){
  vector<long long> res;
  for(int i=1;i<a.size();i++){
    res.push_back(a[i]-a[i-1]);
  }
  sort(res.begin(),res.end());
  return res;
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

    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long oup=-1;
    while(a.size()>=2){
      a=f(a);

      if(a.size()>=2 && a[a.size()-2]==0){oup=a.back();break;}
      if(a.size()>=3){
        long long l1=a[a.size()-1];
        long long l2=a[a.size()-2];
        if(a[a.size()-3]==0 && l1%l2==0){
          long long dec=a.size()-1;
          if((l1-dec*l2)==0){oup=0;}
          else{oup=max(l2,l1-dec*l2);}
          break;
        }
      }
    }
    if(a.size()==1){cout << a[0] << "\n";}
    else{cout << oup << "\n";}
  }
  return 0;
}