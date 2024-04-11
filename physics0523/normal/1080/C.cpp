#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

long long f(long long lu,long long sz){
  if(lu%2==0){
    return llceil(sz,2);
  }
  else{
    return (sz/2);
  }
}

using pl=pair<long long,long long>;
using rect=pair<pl,pl>;

bool insideRect(long long x,long long y,rect rc){
  if(!(rc.first.first<=x && x<=rc.second.first)){return false;}
  if(!(rc.first.second<=y && y<=rc.second.second)){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    set<long long> sx,sy;
    rect w;
    rect b;
    cin >> w.first.first >> w.first.second;
    cin >> w.second.first >> w.second.second;
    cin >> b.first.first >> b.first.second;
    cin >> b.second.first >> b.second.second;

    sx.insert(w.first.first);
    sx.insert(w.second.first+1);
    sx.insert(b.first.first);
    sx.insert(b.second.first+1);

    sy.insert(w.first.second);
    sy.insert(w.second.second+1);
    sy.insert(b.first.second);
    sy.insert(b.second.second+1);

    sx.insert(1);
    sx.insert(m+1);
    sy.insert(1);
    sy.insert(n+1);
    long long rw=0;

    vector<long long> vx,vy;
    for(auto &nx : sx){vx.push_back(nx);}
    for(auto &nx : sy){vy.push_back(nx);}

    int xs=vx.size(),ys=vy.size();

    for(int i=0;i<xs-1;i++){
      for(int j=0;j<ys-1;j++){
        //cout << vx[i] << ' ' << vx[i+1] << ' ';
        //cout << vy[j] << ' ' << vy[j+1] << ':';
        if(insideRect(vx[i],vy[j],b)){
          //cout << "Black\n";
        }
        else if(insideRect(vx[i],vy[j],w)){
          //cout << "White\n";
          rw+=(vx[i+1]-vx[i])*(vy[j+1]-vy[j]);
        }
        else{
          //cout << "Default\n";
          rw+=f((vx[i]+vy[j])%2,(vx[i+1]-vx[i])*(vy[j+1]-vy[j]));
        }
        //cout << rw << '\n';
      }
    }

    cout << rw << ' ' << n*m-rw << '\n';
  }
  return 0;
}