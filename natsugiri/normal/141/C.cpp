#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<string,int> P;

vector<P>v;
bool cmp(P x,P y){
  return x.second>y.second;
}

int main(){
  int n,i,x,j;
  string s;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    cin>>s>>x;
    v.push_back(P(s,x));
  }
  sort(v.begin(),v.end(),cmp);
  
  int a[3000],b[3000];
  for(i=0;i<n;i++)a[i]=i+1;
  for(i=0;i<n;i++){
    int cnt=n-i-v[i].second;
    for(j=0;j<n;j++){
      if(a[j]>0)cnt--;
      if(cnt==0)break;
    }
    if(j==n || a[j]<0){
      puts("-1");
      return 0;
    }
    b[i]=j+1;
    a[j]=-1;
  }
  for(i=0;i<n;i++){
    cout<<v[n-i-1].first<<" "<<b[n-i-1]<<endl;
  }
  return 0;
}