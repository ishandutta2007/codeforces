#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_map>
 
using namespace std;
 
#define rep(X,Y) for(int (X) = 0; (X) < (Y); ++(X))
#define rrep(X,Y) for(int (X) = (Y)-1; (X) >=0; --(X))
#define sz size()
#define X first
#define Y second
#define eb emplace_back
#define pb push_back
#define INF 1000000000
#define all(X) X.begin(),X.end()
typedef long long ll;
 
 
int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<int> a(n),b;
  rep(i,n)
    cin>>a[i];
  b=a;
  sort(all(b));
  unordered_map<int,int> pre,lb,rb,cnt,nxt;
  vector<int> dp(n);
  rep(i,n){
    dp[i]=cnt[a[i]]+1;
    ++cnt[a[i]];
  }
  rep(i,n) rb[a[i]]=i;
  rrep(i,n) lb[a[i]]=i;
  pre[b[0]]=-1;
  rep(i,n-1)
    nxt[b[i]]=b[i+1];
  nxt[b.back()]=-1;
  rep(i,n)if(i)
    if(!pre.count(b[i]))
      pre[b[i]]=b[i-1];
  //for(auto p:pre)cout<<"("<<p.X<<","<<p.Y<<")";cout<<endl;
  unordered_map<int,int> mp,last;
  rep(i,n){
    if(lb[a[i]]==i){
      //cout<<i<<endl;
      int p=pre[a[i]],val;
      if(last.count(p)){
	val=dp[last[p]]+cnt[a[i]];
      }else{
	val=cnt[a[i]];
      }
      int right=rb[a[i]];
      //cout<<right<<":"<<p<<"<"<<val<<endl;
      dp[right]=max(dp[right],val);
    }
    last[a[i]]=i;
  }
  /*
    int x=-1;
    const int tmp=p[a[i]];
    if(rb[tmp]!=last[tmp]){
      if(i==lb[a[i]])
	dp[rb[a[i]]]=min(dp[rb[a[i]]],cnt[
    if(mp.count(a[i]))
      x=mp[a[i]];
    else
      if(mp.count(pre[a[i]]))
	x=mp[pre[a[i]]];
    if(x>=0)
      dp[i]=dp[x]+1;
    else 
      dp[i]=1;
    //cout<<i<<":"<<x<<endl;
    mp[a[i]]=i;
    }*/
  //rep(i,n)cout<<dp[i]<<",";cout<<endl;
  int re=0;
  unordered_map<int,int> count;
  rrep(i,n){
    re=max(dp[i]+count[nxt[a[i]]],re);
    ++count[a[i]];
  }
  cout<<n-re<<endl;
  return 0;
}