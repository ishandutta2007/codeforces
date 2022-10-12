#include<bits/stdc++.h>

using namespace std;

char f(char a,char b,char c,char d){
  for(char i='A';;i++){
    if(a!=i && b!=i && c!=i && d!=i){return i;}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n+2);
  for(int i=0;i<=n+1;i++){
    for(int j=0;j<=m+1;j++){
      s[i].push_back('.');
    }
  }
  for(int p=1;p<=n;p++){
    for(int q=1;q<=m;q++){
      if(s[p][q]!='.'){continue;}
      char c=f(s[p-1][q],s[p][q-1],s[p+1][q],s[p][q+1]);
      int l=0;
      for(int i=1;(p+i)<=n && (q+i)<=m;i++){
        if(s[p-1][q+i]==c || s[p+i][q-1]==c){break;}
        if(c!='A' && s[p-1][q+i]!='A'){break;}
        if(c>='C'){break;}
        bool ok=true;
        for(int j=0;j<=i;j++){
          if(s[p+j][q+i]!='.'){ok=false;}
          if(s[p+i][q+j]!='.'){ok=false;}
        }
        if(!ok){break;}
        l=i;
      }
      for(int pp=0;pp<=l;pp++){
        for(int pq=0;pq<=l;pq++){s[p+pp][q+pq]=c;}
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){cout << s[i][j];}
    cout << '\n';
  }
  return 0;
}