#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  long long sb=0,ss=0,sc=0;
  for(auto &nx : s){
    if(nx=='B'){sb++;}
    if(nx=='S'){ss++;}
    if(nx=='C'){sc++;}
  }
  long long nb,ns,nc;
  cin >> nb >> ns >> nc;
  long long pb,ps,pc;
  cin >> pb >> ps >> pc;
  long long r;
  cin >> r;
  long long st=0,fi=1e13;
  while(st<=fi){
    long long te=(st+fi)/2;
    long long nr=0;
    nr+=pb*max(0ll,sb*te-nb);
    nr+=ps*max(0ll,ss*te-ns);
    nr+=pc*max(0ll,sc*te-nc);
    if(nr<=r){st=te+1;}else{fi=te-1;}
  }
  cout << fi << '\n';
  return 0;
}