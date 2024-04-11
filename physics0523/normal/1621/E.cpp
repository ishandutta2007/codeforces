#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

long long search(long long x,vector<long long> &a){
  int st=0,fi=a.size()-1;
  while(st<=fi){
    int te=(st+fi)/2;
    if(a[te]<x){st=te+1;}
    else{fi=te-1;}
  }
  return st;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;

    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    while(a.size()>m){a.pop_back();}

    a.push_back(-1);
    sort(a.begin(),a.end());

    vector<long long> k(m,0),sig(m,0);
    vector<vector<long long>> b(m);
    vector<long long> cla;
    cla.push_back(-2e9);
    cla.push_back(2e9);
    for(int i=0;i<m;i++){
      cin >> k[i];
      b[i].resize(k[i]);
      for(int j=0;j<k[i];j++){
        cin >> b[i][j];
        sig[i]+=b[i][j];
      }
      cla.push_back(llceil(sig[i],k[i]));
    }
    sort(cla.begin(),cla.end());

    // for(auto &nx : a){cout << nx << ' ';}cout << '\n';
    // for(auto &nx : cla){cout << nx << ' ';}cout << '\n';

    vector<long long> low(m+1,0),cur(m+1,0),upp(m+1,0);
    long long cc=0;
    for(int i=1;i<=m;i++){
      if(cla[i-1]<=a[i]){low[i]++;}
      if(cla[i]<=a[i]){cur[i]++;cc++;}
      if(cla[i+1]<=a[i]){upp[i]++;}
      low[i]+=low[i-1];
      cur[i]+=cur[i-1];
      upp[i]+=upp[i-1];
    }
    string res;
    for(int i=0;i<m;i++){
      for(int j=0;j<k[i];j++){
        long long van=llceil(sig[i],k[i]);
        long long ins=llceil(sig[i]-b[i][j],k[i]-1);
        long long vanpt=search(van,cla);
        long long inspt=search(ins,cla);
        //cout << van << ' ' << ins << ' ' << vanpt << ' ' << inspt << '\n';
        if(vanpt==inspt){
          long long fc=cc;
          if(van<=a[vanpt]){fc--;}
          if(ins<=a[vanpt]){fc++;}
          if(fc==m){res.push_back('1');}else{res.push_back('0');}
          continue;
        }
        else if(vanpt<inspt){
          inspt--;
          if(cur[m]-m != cur[inspt]-inspt){res.push_back('0');}
          else if(cur[vanpt-1]-(vanpt-1) != cur[0]-0){res.push_back('0');}
          else if(upp[inspt-1]-(inspt-1) != upp[vanpt-1]-(vanpt-1)){res.push_back('0');}
          else if(a[inspt]<ins){res.push_back('0');}
          else{res.push_back('1');}
        }
        else{
          if(cur[m]-m != cur[vanpt]-vanpt){res.push_back('0');}
          else if(cur[inspt-1]-(inspt-1) != cur[0]-0){res.push_back('0');}
          else if(low[vanpt]-vanpt != low[inspt]-(inspt)){res.push_back('0');}
          else if(a[inspt]<ins){res.push_back('0');}
          else{res.push_back('1');}
        }
      }
    }
    cout << res << '\n';
  }

  return 0;
}