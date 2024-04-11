#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

// for debug
// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128   p=2777777777777777;
__int128 mod=8777777777777777;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<__int128> pp;
  __int128 val=1;
  for(int i=0;i<262144;i++){
    pp.push_back(val);
    val*=p;val%=mod;
  }

  int n,m;
  string s;
  cin >> n >> m >> s;

  vector<int> cv(26,1000000007);
  vector<vector<int>> mem(n+1);
  mem[n]=cv;
  for(int i=n-1;i>=0;i--){
    cv[s[i]-'a']=i;
    mem[i]=cv;
  }

  vector<string> comp(26);
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++){
      if(s[i]==('a'+j)){comp[j].push_back('#');}
      else{comp[j].push_back('.');}
    }
  }

  // for(int i=0;i<26;i++){cout << comp[i] << '\n';}

  vector<vector<__int128>> hash(26);
  for(int i=0;i<26;i++){
    __int128 ch=0;
    hash[i].push_back(ch);
    for(int j=0;j<n;j++){
      __int128 del=((__int128)comp[i][j])*pp[j];
      ch+=del;ch%=mod;
      hash[i].push_back(ch);
    }
  }

  while(m>0){
    m--;
    int x,y,l;
    cin >> x >> y >> l;
    x--;y--;
    if(x>y){swap(x,y);}
    vector<pi> xl,yl;
    for(int i=0;i<26;i++){
      xl.push_back({mem[x][i],i});
      yl.push_back({mem[y][i],i});
    }
    sort(xl.begin(),xl.end());
    sort(yl.begin(),yl.end());
    bool isok=true;
    for(int i=0;(i<26 && isok);i++){
      int xd=xl[i].first-x;
      int yd=yl[i].first-y;
      if(xd>=l){xd=-1;}
      if(yd>=l){yd=-1;}
      if(xd!=yd){isok=false;break;}
      if(xd==-1){continue;}
      int xk=xl[i].second;
      int yk=yl[i].second;
      // cout << xk << ' ' << yk << '\n';
      // for(int i=0;i<l;i++){cout << comp[xk][x+i];}cout << '\n';
      // for(int i=0;i<l;i++){cout << comp[yk][y+i];}cout << '\n';
      __int128 xh=(mod+hash[xk][x+l]-hash[xk][x])%mod;
      __int128 yh=(mod+hash[yk][y+l]-hash[yk][y])%mod;
      // cout << xh << ' ' << yh << '\n';
      xh*=pp[y-x];xh%=mod;
      // cout << xh << ' ' << yh << '\n';
      if(xh!=yh){isok=false;break;}
      // cout << "ok\n";
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}