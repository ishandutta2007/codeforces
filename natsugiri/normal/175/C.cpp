#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

int n, t;
LL p[111];
LL s;
vector<pair<int, int> >v;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    int k, c;
    scanf("%d%d", &k, &c);
    v.push_back(make_pair(c, k));
    s+=(LL)k;
  }

  scanf("%d", &t);
  for(int i=0; i<t; i++)cin>>p[i];
  for(int i=t-1; i; i--)p[i]-=p[i-1];
  p[t]=s;
  
  sort(v.begin(), v.end());
  
  LL ans=0;
  int h=0;
  for(int i=0;s; i++){
    if(s<p[i])p[i]=s;
    s-=p[i];
    
    for(;p[i];){
      LL x=min(p[i], (LL)v[h].second);
      v[h].second-=x;
      p[i]-=x;
      
      ans+=x*(i+1)*v[h].first;
      if(v[h].second==0)h++;
    }
  }
    
  cout<<ans<<endl;
  return 0;
}