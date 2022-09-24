#include<iostream>
#include<vector>
using namespace std;
struct LT_T{
  int sp,ra,hd,co;
  bool b;
};

int main(){
  int n,i,j,cost,m;
  LT_T lt;
  vector<LT_T>v;
  cin>>n;
  lt.b=1;

  for(i=0;i<n;i++){
    cin>>lt.sp>>lt.ra>>lt.hd>>lt.co;
    v.push_back(lt);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(v[i].sp<v[j].sp&&v[i].ra<v[j].ra&&v[i].hd<v[j].hd)v[i].b=0;
    }
  }
  cost=9999;
  m=-1;
  for(i=0;i<n;i++){
    if(v[i].b&&v[i].co<cost){
      m=i;
      cost=v[i].co;
    }
  }
  cout<<m+1<<endl;
  return 0;
}