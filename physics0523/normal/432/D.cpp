#include<bits/stdc++.h>

using namespace std;


//z-algorithm
//https://snuke.hatenablog.com/entry/2014/12/03/214243

//longest prefix between S & s_i s_i+1 ... s_l
vector<int> z_algorithm(string s){
  int i,j,k,l;
  l=s.size();
  vector<int> arr(l+5,0);

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

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;

  vector<int> z=z_algorithm(s);
  vector<int> mem(s.size()+5,0);
  for(int i=0;i<s.size();i++){
    mem[1]++;
    mem[z[i]+1]--;
  }
  for(int i=2;i<=s.size();i++){mem[i]+=mem[i-1];}

  vector<pi> res;
  for(int i=1;i<=s.size();i++){
    if(mem[i]>0 && z[s.size()-i]==i){
      res.push_back({i,mem[i]});
    }
  }
  cout << res.size() << '\n';
  for(auto &nx : res){
    cout << nx.first << ' ' << nx.second << '\n';
  }
  return 0;
}