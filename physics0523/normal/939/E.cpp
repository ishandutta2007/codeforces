#include<bits/stdc++.h>

using namespace std;

int main(){
  int q;
  scanf("%d",&q);
  double res=0.0;
  vector<long long> arr;
  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==1){
      long long v;
      scanf("%lld",&v);
      arr.push_back(v);

      if(arr.size()>=2){
        arr[arr.size()-1]+=arr[arr.size()-2];
        long long st=0,fi=arr.size()-2,te;
        while(fi-st>=5){
          long long t1=(2*st+fi)/3;
          long long t2=(st+2*fi)/3;
          long long s1=arr[t1]+v;
          long long s2=arr[t2]+v;
          if((__int128)s1*(t2+2) > (__int128)s2*(t1+2)){st=t1+1;}
          else{fi=t2-1;}
        }
        for(long long i=st;i<=fi;i++){
          double mean=((double)(arr[i]+v))/((double)i+2);
          res=max(((double)v)-mean,res);
        }
      }
    }
    else{
      printf("%.12lf\n",res);
    }
  }
  return 0;
}