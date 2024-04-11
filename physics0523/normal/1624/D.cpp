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
    vector<int> bk(32,0);
    for(auto &nx : s){bk[nx-'a']++;}
    int sing=0,doub=0;
    for(int i=0;i<26;i++){
      sing+=bk[i]%2;
      doub+=bk[i]/2;
    }
    int st=1,fi=n;
    while(st<=fi){
      int te=(st+fi)/2;
      int cs=sing,cd=doub;
      bool isok=true;
      for(int i=0;i<k;i++){
        if(te%2==1 && cs==0){
          if(cd==0){isok=false;break;}
          cd--;cs+=2;
        }
        int ds=te%2,dd=te/2;
        if(cs-ds<0 || cd-dd<0){isok=false;break;}
        cs-=ds;cd-=dd;
      }
      if(isok){st=te+1;}
      else{fi=te-1;}
    }
    cout << fi << '\n';
  }
  return 0;
}