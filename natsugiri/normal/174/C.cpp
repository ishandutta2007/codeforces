#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>

using namespace std;
typedef pair<int,int> P;
int n,a[100010];

stack<P>st;
vector<P>v;
int main(){
  
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",a+i);

  P y=P(1,a[0]);
  for(int i=1;i<n;i++){
    P x(1,a[i]);
    for(;y.second>x.second;){
      y.second--;
      v.push_back(P(i-y.first+1,i));
      if(!st.empty()){
	if(st.top().second==y.second){
	  y.first+=(st.top().first);
	  st.pop();
	}
      }
    }
    if(y.second==x.second)y.first+=x.first;
    else{
      st.push(y);
      y=x;
    }
  }
  

  int m=n;
  for(;!st.empty();){
    P x=st.top();st.pop();

    for(;y.second>x.second;){
      y.second--;
      v.push_back(P(m-y.first+1,m));
    }
    y.first+=x.first;
    if(y.second==0){
      m-=y.first;
      if(st.empty())break;
      y=st.top();st.pop();
    }
  }
  
  for(;y.second--;)
    v.push_back(P(1,y.first));

  printf("%d\n",v.size());
  for(int i=0;i<(int)v.size();i++)
    printf("%d %d\n",v[i].first,v[i].second);
  return 0;
}