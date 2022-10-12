#include<bits/stdc++.h>

using namespace std;

typedef struct{
  long long a;
  long long c;
  vector<int> climb;
}node;

node ininode(long long a,long long c){
  node nd;
  nd.a=a;
  nd.c=c;
  nd.climb.resize(20);
  for(auto &nx : nd.climb){nx=-1;}
  return nd;
}

int main(){
  int q;
  long long a,c;
  cin >> q >> a >> c;
  vector<node> narr(q+1);
  narr[0]=ininode(a,c);
  for(int i=1;i<=q;i++){
    int t;
    cin >> t;
    if(t==1){
      int p;
      cin >> p >> a >> c;
      narr[i]=ininode(a,c);
      for(int j=0;j<20;j++){
        narr[i].climb[j]=p;
        p=narr[p].climb[j];
        if(p==-1){break;}
      }
    }
    else{
      int v;
      long long w,res=0,tam=0;
      cin >> v >> w;
      while(w>0){
        int cp=v;
        for(int j=19;j>=0;j--){
          if(narr[cp].climb[j]==-1){continue;}
          if(narr[narr[cp].climb[j]].a>0){cp=narr[cp].climb[j];}
        }
        long long am=min(narr[cp].a,w);
        narr[cp].a-=am;w-=am;tam+=am;
        res+=am*narr[cp].c;
        if(cp==v){break;}
      }
      cout << tam << ' ' << res << '\n';
      fflush(stdout);
    }
  }
  return 0;
}