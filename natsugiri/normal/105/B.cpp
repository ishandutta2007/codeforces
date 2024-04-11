#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;
vector<pair<int,int> >s;
int n,a;
double calc(int v,int p,int A,int B){
  if(p>=n){
    if(v>n/2)return 1.0;
    return (double)A/(A+B);
  }
  int x;
  double ans=0;
  x=min(s[p].second,100);
  ans+=x/100.0*calc(v+1,p+1,A,B);
  ans+=(100-x)/100.0*calc(v,p+1,A,B+s[p].first);
  return ans;
}

double rec(int k,int p){
  if(k<1)return calc(0,0,a,0);
  int i,j;
  double ans=0;
  for(i=p;i<n;i++){
    for(j=0;j<=k;j++){
      s[i].second+=10*j;
      ans=max(rec(k-j,i+1),ans);
      s[i].second-=10*j;
    }
  }
  return ans;
}

int main(){
  int k;
  int i,x,y;
  cin>>n>>k>>a;
  for(i=0;i<n;i++){
    cin>>x>>y;
    s.push_back(pair<int,int>(x,y));
  }
  printf("%.10lf\n",rec(k,0));
  return 0;
}