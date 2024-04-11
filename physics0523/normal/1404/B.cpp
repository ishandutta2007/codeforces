#include<bits/stdc++.h>
#define inf 1072114514
using namespace std;

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

typedef struct{
    long long st;
    long long fi;
    long long kr;
}rs;

typedef struct{
    long long st;
    long long kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st > ((rs*)b)->st){return 1;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 0;
}

void makemkj(rs g[],mkj x[],long long n){
    long long i,ms=0,nst=g[0].st;
    for(i=1;i<n;i++){
        if(g[i].st!=g[i-1].st){
            x[nst].kz=i-ms;
            x[nst].st=ms;
            nst=g[i].st;ms=i;
        }
    }
    x[nst].kz=n-ms;
    x[nst].st=ms;
}

void getperm(int a[],int n){
  int i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=rand()%(i+1);
    swap(a[p],a[i]);
  }
}

int dist[524288];
void dfs(int t,int l,rs g[],mkj x[]){
  int i;
  if(dist[t]<=l){return;}
  dist[t]=l;
  for(i=x[t].st;i<x[t].st+x[t].kz;i++){
    dfs(g[i].fi,l+1,g,x);
  }
}

int tns(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(time(0));
  int n,a,b,da,db,t;
  int perm[524288];
  char s[524288],fl[524288];
  rs g[524288];
  mkj x[524288];
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> da;
    cin >> db;
    getperm(perm,n-1);
    for(int i=0;i<n-1;i++){
      int p,q;
      cin >> p;
      cin >> q;
      g[2*perm[i]].st=p;
      g[2*perm[i]].fi=q;
      g[2*perm[i]].kr=1;
      g[2*perm[i]+1].st=q;
      g[2*perm[i]+1].fi=p;
      g[2*perm[i]+1].kr=1;
    }
    if(db<=2*da){
      cout << "Alice" << '\n';
      continue;
    }
    
    for(int i=0;i<=n;i++){x[i].kz=0;}
    qsort(g,2*(n-1),sizeof(g[0]),sortfnc);
    makemkj(g,x,2*(n-1));
    
    int h,w,r;
    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(1,0,g,x);
    r=0;
    for(int i=1;i<=n;i++){
      if(r<dist[i]){
        h=i;
        r=dist[i];
      }
    }
    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(h,0,g,x);
    r=0;
    for(int i=1;i<=n;i++){
      if(r<dist[i]){
        w=i;
        r=dist[i];
      }
    }
    
    vector<int> hdist(n+1),wdist(n+1),adist(n+1),bdist(n+1);
    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(h,0,g,x);
    for(int i=1;i<=n;i++){
      hdist[i]=dist[i];
    }
    
    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(w,0,g,x);
    for(int i=1;i<=n;i++){
      wdist[i]=dist[i];
    }

    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(a,0,g,x);
    for(int i=1;i<=n;i++){
      adist[i]=dist[i];
    }

    for(int i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(b,0,g,x);
    for(int i=1;i<=n;i++){
      bdist[i]=dist[i];
    }

    if(adist[b]<=da){
      cout << "Alice" << '\n';
      continue;
    }
    
    int lim=2*da,fl=0;
    for(int i=1;i<=n;i++){
      if(hdist[i]<=lim && wdist[i]<=lim){continue;}
      if(tns(bdist[i],db)<tns(adist[i],da)){fl=1;break;}
    }
    
    if(fl==1){
      cout << "Bob" << '\n';
    }
    else{
      cout << "Alice" << '\n';
    }
  }
  return 0;
}