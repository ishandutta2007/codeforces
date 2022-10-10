#include <bits/stdc++.h>
using namespace std;
const int MX=202*202,ME=8*MX;
int n,m,e,S,T,it,i,ii,j,jj,x,fi,fr,cur,a[MX],k[MX],q[MX],pe[MX],u[MX],t[ME],f[ME],c[ME];
vector<int> g[ME];
long long val,flow,r;
bool act[ME];
bool cmp(int x, int y) {
  return a[x]<a[y];
}
void addedge(int fr, int to, int cap, int ocap) {
  t[e]=to; f[e]=0; c[e]=cap;  act[e]=true; g[fr].push_back(e++);
  t[e]=fr; f[e]=0; c[e]=ocap; act[e]=true; g[to].push_back(e++);
}
int main() {
  scanf("%d",&n);
  S=n*n; T=S+1;
  for (cur=i=0; i<n; i++) for (j=0; j<n; j++, cur++) {
    scanf("%d",&a[cur]);
    if (a[cur]>0) {
      k[m++]=cur;
      addedge(cur,T,1000000000,0);
    }
  }
  for (cur=i=0; i<n; i++) for (j=0; j<n; j++, cur++) if (a[cur]>=0) {
    if (i+1<n && a[cur+n]>=0) addedge(cur,cur+n,1,1);
    if (j+1<n && a[cur+1]>=0) addedge(cur,cur+1,1,1);
  }
  sort(k,k+m,cmp);
  for (ii=0; ii<m; ii=jj) {
    for (jj=ii; jj<m && a[k[ii]]==a[k[jj]]; jj++) {
      i=k[jj];
      for (int edge: g[i]) if (t[edge]==T) {
        act[edge]=false;
        act[edge^1]=false;
        while (true) {
          ++it; q[0]=i;
          for (fi=0, fr=1; fi<fr; fi++) {
            x=q[fi];
            for (int edge: g[x]) if (act[edge] && f[edge]<0) {
              j=t[edge];
              if (u[j]!=it) {
                u[j]=it;
                pe[j]=edge;
                q[fr++]=j;
              }
            }
            if (u[S]==it) break;
          }
          if (u[S]!=it) break;
          --flow;
          for (x=S; x!=i; x=t[pe[x]^1]) {
            //printf("decrease %d->%d\n",x,t[pe[x]^1]);
            ++f[pe[x]];
            --f[pe[x]^1];
          }
        }
        break;
      }
      addedge(S,i,1000000000,0);
    }
    if (jj>=m) break;
    val=a[k[jj]]-a[k[ii]];  
    while (true) {
      ++it; q[0]=S;
      for (fi=0, fr=1; fi<fr; fi++) {
        i=q[fi];
        for (int edge: g[i]) if (act[edge] && f[edge]<c[edge]) {
          j=t[edge];
          if (u[j]!=it) {
            u[j]=it;
            pe[j]=edge;
            q[fr++]=j;
          }
        }
        if (u[T]==it) break;
      }
      if (u[T]!=it) break;
      ++flow;
      for (i=T; i!=S; i=t[pe[i]^1]) {
        //printf("increase %d->%d\n",t[pe[i]^1],i);
        ++f[pe[i]];
        --f[pe[i]^1];
      }
    }
    //printf("%d\n",int(flow));
    r+=flow*val;
  }
  printf("%I64d\n",r);
  return 0;
}