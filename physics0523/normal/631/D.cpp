#include<bits/stdc++.h>

using namespace std;
using plc=pair<long long,char>;

vector<plc> getstr(int sz){
  vector<plc> res;
  for(int i=0;i<sz;i++){
    string s;
    cin >> s;
    char cc=s.back();
    s.pop_back();s.pop_back();
    res.push_back({stoll(s),cc});
  }
  return res;
}

vector<plc> comp(vector<plc> org){
  vector<plc> res;
  long long cl=org[0].first;
  char cc=org[0].second;
  for(int i=1;i<org.size();i++){
    if(cc==org[i].second){cl+=org[i].first;}
    else{
      res.push_back({cl,cc});
      cl=org[i].first;
      cc=org[i].second;
    }
  }
  res.push_back({cl,cc});
  return res;
}

//z-algorithm
//https://snuke.hatenablog.com/entry/2014/12/03/214243

//longest prefix between S & s_i s_i+1 ... s_l
vector<int> z_algorithm(vector<plc> &s){
  int i,j,k,l;
  l=s.size();
  vector<int> arr(l);

  arr[0]=l;
  i=1;j=0;
  while(i<l){
    while((i+j)<l){
      if(s[j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    if(j==0){i++;continue;}
    k=1;
    while((i+k)<l){
      if(k+arr[k]>=arr[i]){break;}
      arr[i+k]=arr[k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }

  return arr;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<plc> s=comp(getstr(n));
  vector<plc> t=comp(getstr(m));
  //for(auto &nx : s){cout << nx.first << ' ' << nx.second << '\n';}
  //for(auto &nx : t){cout << nx.first << ' ' << nx.second << '\n';}
  n=s.size();m=t.size();

  vector<plc> z;
  for(int i=1;i<m-1;i++){z.push_back(t[i]);}
  for(int i=0;i<n;i++){z.push_back(s[i]);}
  vector<int> za=z_algorithm(z);

  long long res=0;
  if(t.size()==1){
    for(auto &nx : s){
      if(nx.second==t[0].second){
        res+=max(0ll,nx.first-t[0].first+1ll);
      }
    }
  }
  else{
    for(int i=0;(i+m-1)<n;i++){
      int zpt=(m-2)+i+1;
      if(za[zpt]>=(m-2)){
        if(s[i].second==t[0].second && s[i].first>=t[0].first
        && s[i+m-1].second==t[m-1].second && s[i+m-1].first>=t[m-1].first){
          res++;
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}