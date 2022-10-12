#include<bits/stdc++.h>

using namespace std;

//Binary Indexed Tree
int bit[525252]={0},bsize=524288;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(int i,int x){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

using Graph=vector<set<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  string s;
  cin >> n >> m >> s;
  Graph g(128);
  for(int i=1;i<=n;i++){
    g[(int)s[i-1]].insert(i);
    add(i,1);
  }
  while(m>0){
    m--;
    int a,b;
    string c;
    cin >> a >> b >> c;
    int st,fi,te;

    st=1;fi=n;
    while(st<=fi){
      te=(st+fi)/2;
      if(sum(te)<a){st=te+1;}else{fi=te-1;}
    }a=st;

    st=1;fi=n;
    while(st<=fi){
      te=(st+fi)/2;
      if(sum(te)<b){st=te+1;}else{fi=te-1;}
    }b=st;

    while(1){
      auto it=g[(int)c[0]].lower_bound(a);
      if(it==g[(int)c[0]].end()){break;}
      if((*it)>b){break;}
      add((*it),-1);
      g[(int)c[0]].erase(it);
    }
  }
  for(int i=1;i<=n;i++){
    if(sum(i)!=sum(i-1)){cout << s[i-1];}
  }cout << '\n';
  return 0;
}