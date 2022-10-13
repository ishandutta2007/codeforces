#include<bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;

void ope(vector<int> &kind,vector<int> &arr){
  vector<int> res=arr;
  int mp=arr.size();
  int m=kind.size();
  int us=0;
  for(int i=0;i<m;i++){
    int stt=mp-kind[i];
    for(int j=0;j<kind[i];j++){
      res[stt+j]=arr[us];
      us++;
    }
    mp-=kind[i];
  }
  res.swap(arr);
}

void resout(Graph &res){
  int n=res.size();
  cout << n << '\n';
  for(int i=0;i<n;i++){
    int m=res[i].size();
    cout << m;
    for(int j=0;j<m;j++){
      cout << ' ';
      cout << res[i][j];
    }
    cout << '\n';
  }
  return;
}

int main(){
  int n;
  Graph res;
  cin >> n;
  if(n==1){cout << "0\n";return 0;}
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
  }
  int lim=n;
  if(lim%2==1){lim--;}
  int fr=1,bk=n;
  int fc=-1,bc=n-1;
  //cout << fc << ' ' << bc << '\n';
  for(int i=0;i<lim;i++){
    vector<int> co;
    int fl,cnt=1;//cout << i << ':';
    //for(auto x: p){cout << x << ' ';}cout << '\n';
    //cout << fc << ' ' << bc << '\n';
    if(i%2==0){
      for(int j=0;j<n;j++){
        fl=0;
        if(j<=fc || bc<=j){fl=1;}
        if(j!=n-1){
          if(p[j+1]==bk){fl=1;}
        }
        if(j==n-1){fl=1;}
        if(fl==1){co.push_back(cnt);cnt=1;}
        else{cnt++;}
      }
      bk--;
      fc++;
    }
    else{
      for(int j=0;j<n;j++){
        fl=0;
        if(j<=fc || bc<=j){fl=1;}
        if(j!=n-1){
          if(p[j+1]==fr){fl=1;}
        }
        if(j==n-1){fl=1;}
        if(fl==1){co.push_back(cnt);cnt=1;}
        else{cnt++;}
      }
      fr++;
      bc--;
    }
    ope(co,p);
    //for(auto x: p){cout << x << ' ';}cout << '\n';
    if(co.size()!=1){res.push_back(co);}
  }
  //for(auto x: p){cout << x << ' ';}cout << '\n';
  resout(res);
}