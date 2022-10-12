#include<bits/stdc++.h>

using namespace std;

int ask(int t,int i,int j,int x){
  printf("? %d %d %d %d\n",t,i,j,x);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

void output(vector<int> &p){
  printf("!");
  for(auto &nx : p){
    printf(" %d",nx);
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());

  int tc;
  scanf("%d",&tc);
  while(tc>0){
    tc--;
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++){a[i]=i+1;}

    int tg=-1;
    while(tg==-1){
      vector<int> b;
      if(a.size()==1){tg=a[0];break;}
      shuffle(a.begin(),a.end(),engine);
      for(int i=1;i<a.size();i+=2){
        int qv=ask(1,a[i-1],a[i],n-1);
        if(qv<(n-1)){continue;}
        if(qv==n){tg=a[i];break;}
        b.push_back(a[i-1]);
        b.push_back(a[i]);
      }
      if(a.size()%2){b.push_back(a[a.size()-1]);}
      a.swap(b);
    }
    vector<int> p(n);
    for(int i=1;i<=n;i++){
      if(i==tg){p[i-1]=n;continue;}
      p[i-1]=ask(2,i,tg,1);
    }
    output(p);
  }
  return 0;
}