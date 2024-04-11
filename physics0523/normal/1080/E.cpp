#include<bits/stdc++.h>

using namespace std;

//manacher algorithm
//http://snuke.hatenablog.com/entry/2014/12/02/235837

//longest palindrome(length:odd)
//if you want to find the answer for even palindrome,
//you can use dummy letter.
//ex. $a$b$c$c$b$a$
vector<int> manacher(vector<uint64_t> s){
  vector<int> arr(s.size());
  int i,j,k,l;
  l=s.size();
  i=0;j=0;
  while(i<l){
    while((i-j)>=0 && (i+j)<l){
      if(s[i-j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    k=1;
    while((i-k)>=0 && (i+k)<l){
      if(k+arr[i-k]>=arr[i]){break;}
      arr[i+k]=arr[i-k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }
  return arr;
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<uint64_t>> hmem(26,vector<uint64_t>(334));
  for(auto &nx : hmem){
    for(int i=1;i<334;i++){
      nx[i]=engine();
    }
  }

  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}
  long long res=0;
  for(int l=0;l<m;l++){
    vector<int> bt(n,0);
    vector<int> pc(n,0);
    vector<vector<int>> a(n,vector<int>(26,0));
    vector<uint64_t> hs(n,0);
    for(int r=l;r<m;r++){
      vector<uint64_t> str={0};
      vector<bool> fl={false};
      for(int i=0;i<n;i++){
        //cerr << l << ' ' << r << ' ' << i << "ok\n";
        int cc=s[i][r]-'a';
        hs[i]^=hmem[cc][a[i][cc]];
        a[i][cc]++;
        hs[i]^=hmem[cc][a[i][cc]];
        bt[i]^=(1<<(cc));
        if(bt[i]&(1<<cc)){pc[i]++;}
        else{pc[i]--;}

        if(pc[i]<=1){
          str.push_back(hs[i]);
          fl.push_back(false);
        }
        else{
          str.push_back(engine());
          fl.push_back(true);
        }
        str.push_back(0);
        fl.push_back(false);
      }
      vector<int> mn=manacher(str);
      long long dlt=0;
      for(int i=0;i<str.size();i++){
        if(fl[i]){continue;}
        dlt+=mn[i];
      }
      dlt-=(n+1);
      dlt/=2;
      res+=dlt;
    }
  }
  cout << res << '\n';
  return 0;
}