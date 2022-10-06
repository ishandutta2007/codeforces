#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<utility>
#include<numeric>

#define X first
#define Y second
#define rep(X,Y) for(int (X)=0;(X)<(Y);(X)++)
#define all(X) X.begin(),X.end()

using namespace std;
typedef pair<int,int> pii;

int main(){
  int n,i,j,k;
  cin>>n;
  vector<pii> v(n);
  vector<int> a(n),b(n);
  //  v=iota(all(v));
  rep(i,n){
    cin>>v[i].X;
    v[i].Y=i;
  }
  sort(all(v));
  for(i=0;i<(n+2)/3;i++){
    a[v[i].Y]=v[i].X;
    b[v[i].Y]=0;
  }
  for(j=0;i<n;i++){
    if(i%2){
      a[v[i].Y]=0;
      b[v[i].Y]=v[i].X;
    }else{
      a[v[i].Y]=v[i].X-j;
      b[v[i].Y]=j++;
    }
  }
  cout << "YES" << endl;
  rep(i,n)cout<<a[i]<<" ";cout<<endl;
  rep(i,n)cout<<b[i]<<" ";cout<<endl;
  return 0;
}