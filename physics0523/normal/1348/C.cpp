#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    string s;
    cin >> n >> k >> s;
    if(k==1){
      sort(s.begin(),s.end());
      cout << s << '\n';
      continue;
    }

    vector<int> bk(26,0);
    for(auto &nx : s){bk[nx-'a']++;}
    string res;
    for(int l=0;;l++){
      int a=-1;
      for(int i=0;i<26;i++){
        if(bk[i]>0){a=i;break;}
      }
      int b=-1;
      for(int i=a+1;i<26;i++){
        if(bk[i]>0){b=i;break;}
      }
      int c=-1;
      for(int i=b+1;i<26;i++){
        if(bk[i]>0){c=i;break;}
      }
      int z=-1;
      for(int i=25;i>=0;i--){
        if(bk[i]>0){z=i;break;}
      }

      if(a==z){
        int cnt=ceil(bk[a],k);
        for(int i=0;i<cnt;i++){res.push_back('a'+a);}
        break;
      }
      else if(bk[a]>k){
        if(l==0){bk[a]-=(k-1);}
        for(int i=0;i<26;i++){
          for(int j=0;j<bk[i];j++){
            res.push_back('a'+i);
          }
        }
        break;
      }
      else if(bk[a]==k){
        if(c==-1){
          bk[a]-=k;
          res.push_back('a'+a);
          continue;
        }
        else{
          if(l==0){bk[a]-=(k-1);}
          for(int i=0;i<26;i++){
            for(int j=0;j<bk[i];j++){
              res.push_back('a'+i);
            }
          }
          break;
        }
      }
      else{
        for(int i=0;i<26;i++){
          if(k<=bk[i]){
            res.push_back('a'+i);
            break;
          }
          k-=bk[i];
        }
        break;
      }
    }

    cout << res << '\n';
  }
  return 0;
}