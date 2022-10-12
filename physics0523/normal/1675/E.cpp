#include<bits/stdc++.h>

using namespace std;

int mem[26][26][26][26];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  {
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        for(int k=0;k<=j;k++){
          for(int l=0;l<26;l++){mem[i][j][k][l]=l;}
          for(int p=i;p>0;p--){
            for(int q=0;q<26;q++){
              if(mem[i][j][k][q]==p){mem[i][j][k][q]--;}
            }
          }
          int tg=j;
          for(int p=0;p<k;p++){
            for(int q=0;q<26;q++){
              if(mem[i][j][k][q]==tg){mem[i][j][k][q]--;}
            }
            tg--;
          }
        }
      }
    }
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l=s.size();
    string res=s;
    k=min(k,26);


    for(int i=0;i<=min(k,25);i++){
      for(int j=0;j<=25;j++){
        int rem=min(j,k-i);

        string cr;
        for(int p=0;p<l;p++){
          cr.push_back('a'+mem[i][j][rem][s[p]-'a']);
        }
        res=min(res,cr);
      }
    }
    cout << res << '\n';
  }
  return 0;
}