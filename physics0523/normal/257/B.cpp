#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int res=0;

  {
    int cres=0;
    int cn=n,cm=m;
    vector<int> v;
    v.push_back(0);cn--;
    int d=1;
    while(cn>0 || cm>0){
      if(d%2){
        if(v.back()==0){
          if(cm>0){v.push_back(1);cm--;}
          else{v.push_back(0);cn--;}
        }
        else{
          if(cn>0){v.push_back(0);cn--;}
          else{v.push_back(1);cm--;}
        }
      }
      else{
        if(v.back()==0){
          if(cn>0){v.push_back(0);cn--;}
          else{v.push_back(1);cm--;}
        }
        else{
          if(cm>0){v.push_back(1);cm--;}
          else{v.push_back(0);cn--;}
        }
      }
      d++;
    }
    //cout << v[0];
    for(int i=1;i<v.size();i++){
      //cout << v[i];
      if(v[i-1]==v[i]){cres++;}
    }//cout << '\n';
    res=max(cres,res);
  }

  {
    int cres=0;
    int cn=n,cm=m;
    vector<int> v;
    v.push_back(1);cm--;
    int d=1;
    while(cn>0 || cm>0){
      if(d%2){
        if(v.back()==0){
          if(cm>0){v.push_back(1);cm--;}
          else{v.push_back(0);cn--;}
        }
        else{
          if(cn>0){v.push_back(0);cn--;}
          else{v.push_back(1);cm--;}
        }
      }
      else{
        if(v.back()==0){
          if(cn>0){v.push_back(0);cn--;}
          else{v.push_back(1);cm--;}
        }
        else{
          if(cm>0){v.push_back(1);cm--;}
          else{v.push_back(0);cn--;}
        }
      }
      d++;
    }
    //cout << v[0];
    for(int i=1;i<v.size();i++){
      //cout << v[i];
      if(v[i-1]==v[i]){cres++;}
    }//cout << '\n';
    res=max(cres,res);
  }

  cout << res << ' ' << (n+m-1)-res << '\n';
  return 0;
}