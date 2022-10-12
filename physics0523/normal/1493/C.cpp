#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n%k){cout << "-1\n";continue;}
    int st=0,fi=n;
    while(st<=fi){
      int te=(st+fi)/2;
      vector<int> bk(26,0);
      string cur;
      for(int i=0;i<te;i++){
        cur.push_back(s[i]);
        bk[s[i]-'a']++;
      }
      string suf;
      for(int i=0;i<26;i++){
        while(cur.size()+suf.size()<=n && bk[i]%k!=0){
          suf.push_back('a'+i);
          bk[i]++;
        }
      }
      while(cur.size()+suf.size()<n){suf.push_back('z');}
      reverse(suf.begin(),suf.end());
      cur=cur+suf;
      if(cur.size()!=n){fi=te-1;continue;}
      if(s<=cur){st=te+1;}else{fi=te-1;}
    }

    if(fi==n){
      cout << s << '\n';
      continue;
    }
    string res="{";
    for(char th=s[fi]+1;th<='z';th++){
      string cur;
      for(int i=0;i<fi;i++){cur.push_back(s[i]);}
      cur.push_back(th);
      vector<int> bk(26,0);
      for(auto &nx : cur){bk[nx-'a']++;}
      string suf;
      for(int i=25;i>=0;i--){
        while(cur.size()+suf.size()<=n && bk[i]%k!=0){
          suf.push_back('a'+i);
          bk[i]++;
        }
      }
      while(cur.size()+suf.size()<n){suf.push_back('a');}
      reverse(suf.begin(),suf.end());
      cur=cur+suf;
      if(cur.size()==n){res=min(res,cur);}
    }
    cout << res << '\n';
    // cout << fi << '\n';
  }
  return 0;
}