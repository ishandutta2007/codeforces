#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int forb(){
  int v;
  scanf("%d",&v);
  return v;
}

set<pi> st;
void put(int a,int b,int c){
  printf("%d %d %d\n",c,a,b);
  st.erase(make_pair(a,b));
  fflush(stdout);
}

int main(){
  int n;
  scanf("%d",&n);
  queue<pi> tg1,tg2;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      st.insert(make_pair(i,j));
      if((i+j)%2){tg1.push(make_pair(i,j));}
      else{tg2.push(make_pair(i,j));}
    }
  }
  for(int i=0;i<n*n;i++){
    int f=forb();
    if(tg1.empty()){
      auto it=st.begin();
      pi od=(*it);
      if(f!=2){put(od.first,od.second,2);}
      else{put(od.first,od.second,3);}
    }
    else if(tg2.empty()){
      auto it=st.begin();
      pi od=(*it);
      if(f!=1){put(od.first,od.second,1);}
      else{put(od.first,od.second,3);}
    }
    else if(f!=1){
      pi od=tg1.front();tg1.pop();
      put(od.first,od.second,1);
    }
    else{
      pi od=tg2.front();tg2.pop();
      put(od.first,od.second,2);
    }
  }
  return 0;
}