#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>v;
vector<pair<string,string> >bad;
int n,m;
bool use[16];

vector<string> rec(int p,vector<string>w){
  if(p==n)return w;
  int i,j;
  vector<string>ans,tmp;
  vector<int>d;
  ans=rec(p+1,w);
  if(use[p]){
    for(i=0;i<bad.size();i++){
      if(bad[i].first==v[p]){
	for(j=0;j<n;j++){
	  if(v[j]==bad[i].second&&use[j]){
	    use[j]=false;
	    d.push_back(j);
	  }
	}
      }
    }
    w.push_back(v[p]);
    tmp=rec(p+1,w);
    for(i=0;i<d.size();i++){
      use[d[i]]=true;
    }
  }
  if(ans.size()<tmp.size())ans=tmp;
  return ans;
}
      
int main(){
  string s,t;
  vector<string>ans;
  int i;
  cin>>n>>m;
  for(i=0;i<n;i++){
    cin>>s;
    v.push_back(s);
    use[i]=true;
  }
  for(i=0;i<m;i++){
    cin>>s>>t;
    bad.push_back(pair<string,string>(s,t));
    bad.push_back(pair<string,string>(t,s));
  }
  ans=rec(0,ans);
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
  
  return 0;
}