#include<bits/stdc++.h>

using namespace std;

int n;
int ask(int x1,int y1,int x2,int y2){
  cout << "?";
  cout << ' ' << x1 << ' ' << y1;
  cout << ' ' << x2 << ' ' << y2;
  cout << '\n';
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

void ans(int x1,int y1,int x2,int y2){
  cout << "!";
  cout << ' ' << x1 << ' ' << y1;
  cout << ' ' << x2 << ' ' << y2;
  cout << '\n';
  fflush(stdout);
}

int main(){
  cin >> n;
  int xl=1e9,xr=-1e9;
  for(int i=1;i<n;i++){
    if(ask(1,1,i,n)%2){
      xl=min(xl,i);
      xr=max(xr,i+1);
    }
  }
  int yl=1e9,yr=-1e9;
  for(int i=1;i<n;i++){
    if(ask(1,1,n,i)%2){
      yl=min(yl,i);
      yr=max(yr,i+1);
    }
  }
  vector<pair<int,int>> res;
  if(xr>0 && yr>0){
    if(ask(xl,yl,xl,yl)==1){res.push_back({xl,yl});}
    if(ask(xl,yr,xl,yr)==1){res.push_back({xl,yr});}
    if(ask(xr,yl,xr,yl)==1){res.push_back({xr,yl});}
    if(ask(xr,yr,xr,yr)==1){res.push_back({xr,yr});}
  }
  else if(xr>0){
    int st,fi;
    st=1;fi=n-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(ask(xl,1,xl,te)%2){fi=te-1;}
      else{st=te+1;}
    }
    res.push_back({xl,st});

    st=1;fi=n-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(ask(xr,1,xr,te)%2){fi=te-1;}
      else{st=te+1;}
    }
    res.push_back({xr,st});
  }
  else{
    int st,fi;
    st=1;fi=n-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(ask(1,yl,te,yl)%2){fi=te-1;}
      else{st=te+1;}
    }
    res.push_back({st,yl});

    st=1;fi=n-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(ask(1,yr,te,yr)%2){fi=te-1;}
      else{st=te+1;}
    }
    res.push_back({st,yr});
  }

  ans(res[0].first,res[0].second,res[1].first,res[1].second);
  return 0;
}