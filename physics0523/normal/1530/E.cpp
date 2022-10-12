#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int n=s.size();

    if(s.size()<=2){
      sort(s.begin(),s.end());
      cout << s << '\n';
      continue;
    }

    map<char,int> mp;
    for(auto &nx : s){mp[nx]++;}
    if(mp.size()==1){cout << s << '\n';continue;}
    int mi=1072114514;
    for(auto &nx : mp){mi=min(mi,nx.second);}
    if(mi==1){
      char tg;
      for(char i='a';i<='z';i++){
        if(mp[i]==1){tg=i;break;}
      }
      cout << tg;
      for(char i='a';i<='z';i++){
        if(i==tg){continue;}
        for(int j=0;j<mp[i];j++){
          cout << i;
        }
      }
      cout << '\n';
      continue;
    }

    bool solved=false;

    for(char i='a';i<='z';i++){
      if(solved){break;}
      for(char j='a';j<='z';j++){
        if(solved){break;}

        mp[i]--;mp[j]--;
        if(mp[i]<0 || mp[j]<0){
          mp[i]++;mp[j]++;continue;
        }
        if(i==j){
          int rem=n-2;
          if(mp[i]>(rem/2)){mp[i]++;mp[j]++;continue;}
          else{
            solved=true;
            string res;
            res.push_back(i);res.push_back(j);
            for(int k=2;k<n;k++){
              if(k%2==1 && mp[i]>0){
                mp[i]--;
                res.push_back(i);
                continue;
              }
              for(char cc='a';cc<='z';cc++){
                if(cc==i){continue;}
                if(mp[cc]>0){
                  mp[cc]--;
                  res.push_back(cc);
                  break;
                }
              }
            }
            cout << res << '\n';
            continue;
          }
        }
        else{
          solved=true;
          string res;
          res.push_back(i);res.push_back(j);
          int rem=n-2;
          if(mp[i]+mp[j]==rem){
            for(int k=0;k<mp[j];k++){res.push_back(j);}
            for(int k=0;k<mp[i];k++){res.push_back(i);}
          }
          else{
            for(int k=0;k<mp[i];k++){res.push_back(i);}
            mp[i]=0;
            bool fin=true;
            for(int k=0;(fin);k++){
              for(char cc='a';cc<='z';cc++){
                if(k==0 && cc==j){continue;}
                if(mp[cc]>0){
                  mp[cc]--;
                  res.push_back(cc);
                  break;
                }
                if(cc=='z'){fin=false;}
              }
            }
          }
          cout << res << '\n';
          continue;
        }
        mp[i]++;mp[j]++;
      }
    }
  }
  return 0;
}