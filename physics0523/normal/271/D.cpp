#include<bits/stdc++.h>

using namespace std;

typedef struct{
  int tg[32];
}node;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,fl;
  cin >> s >> fl;
  int bd;
  cin >> bd;
  int l=s.size();

  node init;
  for(int i=0;i<32;i++){init.tg[i]=-1;}
  vector<node> v={init};

  for(int i=0;i<l;i++){
    int cv=0,rem=bd;
    for(int j=i;j<l;j++){
      rem-=('1'-fl[s[j]-'a']);
      if(rem<0){break;}
      int nn=v[cv].tg[s[j]-'a'];
      if(nn==-1){
        v[cv].tg[s[j]-'a']=v.size();
        v.push_back(init);
      }
      cv=v[cv].tg[s[j]-'a'];
    }
  }
  cout << v.size()-1 << '\n';
  return 0;
}