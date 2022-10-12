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
    int l=s.size();
    int op=(l/2),cl=(l/2);
    for(int i=0;i<l;i++){
      if(s[i]=='('){op--;}
      else if(s[i]==')'){cl--;}
    }
    if(op==0 || cl==0){cout << "YES\n";continue;}

    bool trig=true;
    for(int i=0;i<l;i++){
      if(s[i]=='?'){
        if((op==1) && trig){
          s[i]=')';
          trig=false;
          cl--;
        }
        else if(op>0){
          s[i]='(';
          op--;
        }
        else{
          s[i]=')';
          cl--;
        }
      }
    }
    int h=0;
    bool ng=true;
    for(int i=0;i<l;i++){
      if(s[i]=='('){h++;}else{h--;}
      if(h<0){ng=false;break;}
    }
    if(ng){cout << "NO\n";}else{cout << "YES\n";}
  }
  return 0;
}