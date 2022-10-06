#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int n,k,a[212];

int main(){
  int i,j;
  scanf("%d %d",&n,&k);
  for(i=0;i<n;i++)
    scanf("%d",a+i);
  int l,r,re=-100000,sum;
  for(l=0;l<n;l++){
    for(r=l;r<n;r++){
      vector<int> ins,outs;
      sum=0;
      for(i=0;i<n;i++){
        if(l<=i && i<=r){
          ins.pb(a[i]);
          sum+=a[i];
        }else{
          outs.pb(a[i]);
        }
      }
      sort(ins.begin(),ins.end());
      sort(outs.begin(),outs.end());
   //   cout<<"["<<l<<","<<r<<"]:"<<sum;
      for(i=0;i<k&&i<r-l+1&&i<n-r+l-1;i++){
        if(ins[i]>=outs[outs.size()-1-i])break;
        sum+=-ins[i]+outs[outs.size()-1-i];
 //       cout<<"->"<<sum;
      }
//      for(i=0;i<outs.size();i++)
//        cout<<outs[i]<<" ";
//      cout<<"|";
 //     for(i=0;i<ins.size();i++)cout<<ins[i]<<" ";
 //     cout<<endl;
      re=max(re,sum);
    }
  }
  cout<<re<<endl;
  return 0;
}