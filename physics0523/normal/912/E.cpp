#include<bits/stdc++.h>

using namespace std;

void rep(long long cv,int pos,vector<long long> &p,vector<long long> &res){
  if(pos==p.size()){res.push_back(cv);return;}
  long long k=1;
  double pred=cv;
  while(1){
    if(pred>2.0e18){return;}
    rep(cv*k,pos+1,p,res);
    pred*=p[pos];
    k*=p[pos];
  }
}

int main(){
  int n;
  cin >> n;
  vector<long long> p(n);
  for(int i=0;i<n;i++){cin >> p[i];}
  long long k;
  cin >> k;

  sort(p.begin(),p.end());
  vector<long long> fp,sp;
  for(int i=0;i<n;i++){
    if(i%4==0 || i%4==3){fp.push_back(p[i]);}
    else{sp.push_back(p[i]);}
  }
  vector<long long> fr,sr;
  rep(1,0,fp,fr);
  rep(1,0,sp,sr);
  sort(fr.begin(),fr.end());
  sort(sr.begin(),sr.end());
  long long st=1,fi=1500000000000000000,te;
  while(st<=fi){
    te=(st+fi)/2;
    long long ct=0;
    int fp=0,sp=sr.size()-1;
    while(fp<fr.size() && sp>=0){
      if(((double)fr[fp])*(double)sr[sp]>2.0e18){sp--;}
      if(fr[fp]*sr[sp]>te){sp--;}
      else{ct+=(sp+1);fp++;}
    }
    if(ct<k){st=te+1;}else{fi=te-1;}
  }
  cout << st << '\n';
  return 0;
}