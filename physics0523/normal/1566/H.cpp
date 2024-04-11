#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

long long get_rand(long long lim,mt19937_64 &eg){
  return (long long)(eg()%lim);
}

int main(){
  uint_fast64_t seed=160912202105230523;
  mt19937_64 engine(seed);

  int c,n;
  cin >> c >> n;

  // Step 1 Go
  // prime factorization
  vector<vector<int>> pfact(c+1);
  vector<int> simp(c+1,1);
  vector<int> qask;
  vector<int> qres;
  vector<bool> fl(c+1,true);
  for(int i=2;i<=c;i++){
    if(!pfact[i].empty()){continue;}
    for(int j=i;j<=c;j+=i){
      simp[j]*=i;
      if((j/i)%i==0){fl[j]=false;}
      int v=j;
      while(v%i==0){pfact[j].push_back(i);v/=i;}
    }
  }
  for(int i=1;i<=c;i++){if(fl[i]){qask.push_back(i);}}
  cout << qask.size();
  for(auto &nx : qask){cout << ' ' << nx;}
  cout << '\n';
  fflush(stdout);
  qres.resize(qask.size());
  for(auto &nx : qres){cin >> nx;}
  // Step 1 Finish

  // Step 2 Go
  // f[U] ... xor-sum(i) s.t. the set of pfact for i is exact U
  vector<int> f(c+1);
  f[1]=qres[0];
  // first, f[U] ... xor-sum(i) s.t. i has at least one pfact of U
  for(int i=1;i<qask.size();i++){
    f[qask[i]]=qres[i]^qres[0]; //qres[0] = [? 1]
  }
  for(int i=c;i>=2;i--){
    if(!fl[i]){continue;}
    for(int j=1;j<(1<<pfact[i].size())-1;j++){
      int v=1;
      for(int k=0;k<pfact[i].size();k++){
        if(j&(1<<k)){v*=pfact[i][k];}
      }
      f[i]^=f[v];
    }
  }
  // now, f[U] ... xor-sum(i) s.t. i has all pfact of U(others are no matter)
  for(int i=c;i>=2;i--){
    if(!fl[i]){continue;}
    for(int j=0;j<(1<<pfact[i].size())-1;j++){
      int v=1;
      for(int k=0;k<pfact[i].size();k++){
        if(j&(1<<k)){v*=pfact[i][k];}
      }
      f[v]^=f[i];
    }
  }
  // Step 2 Finish

  // Step 3 Go
  // Let's find the answer!
  // ... "find"? maybe the correct word is "construct"
  vector<int> res;
  vector<pi> pv;
  vector<vector<int>> g(c+1);
  for(int i=1;i<=c;i++){
    int v=1;
    g[simp[i]].push_back(i);
  }
  for(int i=1;i<=c;i++){
    if(!g[i].empty()){pv.push_back({g[i].size(),i});}
  }
  sort(pv.begin(),pv.end());

  int curcd=0,cursz=0;
  int remcd=c,remsz=n;
  for(int pvpt=0;pvpt<pv.size();pvpt++){
    int tg=pv[pvpt].second;
    int aim=f[tg];

    //pref = preferred size
    int csz=pv[pvpt].first;
    double pacemaker=((double)(curcd+csz))*(((double)n)/((double)c));
    pacemaker+=0.5;
    pacemaker-=cursz;
    int pref=pacemaker;
    pref=min(pref,csz);
    pref=max(pref,0);

    assert(0<=remsz && remsz<=remcd);
    bool islast=false;
    if(pvpt==pv.size()-1){
      islast=true;
      pref=remsz;
    }

    // XOR sweeping
    vector<int> ccd=g[tg];
    shuffle(ccd.begin(),ccd.end(),engine);
    vector<int> sweep=ccd;
    vector<int> ind,sub;
    for(int i=0;i<csz;i++){
      int tg=-1;
      for(int j=0;j<20;j++){
        if(sweep[i]&(1<<j)){tg=j;break;}
      }
      if(tg==-1){sub.push_back(ccd[i]);continue;}
      for(int j=i+1;j<csz;j++){
        if(sweep[j]&(1<<tg)){sweep[j]^=sweep[i];}
      }
      ind.push_back(ccd[i]);
    }

    // Find a set
    vector<int> curres;
    do{
      curres.clear();
      int faim=aim;
      // add sub
      shuffle(sub.begin(),sub.end(),engine);
      int cpref;
      if(islast){
        cpref=max(0,pref-(int)get_rand(1+ind.size(),engine));
      }
      else{
        cpref=ind.size()/2;
        if(ind.size()%2 && get_rand(2,engine)==0){cpref++;}
        cpref=max(0,pref-cpref);
      }
      for(int i=0;i<min(cpref,(int)sub.size());i++){
        curres.push_back(sub[i]);
        faim^=sub[i];
      }
      // solve ind
      sweep=ind;
      vector<int> sol(ind.size(),0);
      vector<int> flag;
      for(int i=0;i<ind.size();i++){sol[i]=(1<<i);}
      for(int i=0;i<ind.size();i++){
        int tg=-1;
        for(int j=0;j<20;j++){
          if(sweep[i]&(1<<j)){tg=j;break;}
        }
        flag.push_back(tg);
        for(int j=i+1;j<ind.size();j++){
          if(sweep[j]&(1<<tg)){
            sweep[j]^=sweep[i];
            sol[j]^=sol[i];
          }
        }
      }
      for(int i=ind.size()-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
          if(sweep[j]&(1<<flag[i])){
            sweep[j]^=sweep[i];
            sol[j]^=sol[i];
          }
        }
      }
      int fsol=0;
      for(int i=0;i<ind.size();i++){if(faim&(1<<flag[i])){fsol^=sol[i];}}
      for(int i=0;i<ind.size();i++){if(fsol&(1<<i)){curres.push_back(ind[i]);}}
      if(islast){
        if(remsz==curres.size()){break;}
      }
    }while(islast);
    for(auto &nx : curres){res.push_back(nx);}
    cursz+=curres.size();
    remsz-=curres.size();
    curcd+=csz;
    remcd-=csz;
  }

  assert(res.size()==n);
  sort(res.begin(),res.end());
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  fflush(stdout);
  // Step 3 Finish

  return 0;
}