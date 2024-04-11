#include<bits/stdc++.h>

using namespace std;

int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

int cp[64]={0,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9};
int cq[64]={0,1,1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6,1,2,3,4,5,6,7,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,9};

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,n,m,k,a,b,c,h,w,r=0,l,t,p,q;
  int odc[262144]={0};
  int infl[262144][10][10]={0};
  int errfl[64]={0};
  int errsc[64][64]={0};
  int perm[16];
  sd edge[262144][16];
  cin >> n;
  cin >> m;
  cin >> k;
  for(i=0;i<m;i++){
    cin >> a;
    cin >> b;
    cin >> c;
    edge[a][odc[a]].val=c;
    edge[a][odc[a]].node=b;
    odc[a]++;
  }
  for(i=1;i<=n;i++){
    qsort(edge[i],odc[i],sizeof(edge[i][0]),sdsortfnc);
    for(j=0;j<odc[i];j++){
      infl[edge[i][j].node][odc[i]][j+1]++;
    }
  }
  for(i=1;i<=n;i++){
    w=0;
    for(p=1;p<=9;p++){
      for(q=1;q<=p;q++){
        w++;
        if(infl[i][p][q]>=2){errfl[w]=1;}
      }
    }
    for(p=1;p<=45;p++){
      if(infl[i][cp[p]][cq[p]]!=1){continue;}
      for(q=1;q<=45;q++){
        if(infl[i][cp[q]][cq[q]]!=1){continue;}
        if(infl[i][cp[p]][cq[p]]+infl[i][cp[q]][cq[q]]>=2){
          errsc[p][q]=1;
          errsc[q][p]=1;
        }
      }
    }
  }
  w=fact(k);
  for(i=0;i<w;i++){
    l=i;
    for(j=k;j>=1;j--){
      perm[j]=(l%j);
      l/=j;
    }
    l=1;
    for(j=1;j<=k;j++){
      perm[j]+=l;
      l+=j;
      if(errfl[perm[j]]==1){goto MISTAKE;}
    }
    for(p=1;p<=9;p++){
      for(q=p+1;q<=9;q++){
        if(errsc[perm[p]][perm[q]]==1){goto MISTAKE;}
      }
    }
    r++;
    continue;
    MISTAKE:
    continue;
  }
  cout << r << '\n';
  return 0;
}