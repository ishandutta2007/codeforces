#include<bits/stdc++.h>

using namespace std;

unordered_map<int,int> bit;
int bsize=1000000007;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(int i,int x){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

int search(int x,vector<int> &a){
  int n=a.size();
  int st=0,fi=n-1,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(a[te]<x){st=te+1;}else{fi=te-1;}
  }
  return st;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,int> a;
  for(int i=0;i<n;i++){
    int p,q;
    cin >> p >> q;
    if(a[p]==0){a[p]=p;}
    if(a[q]==0){a[q]=q;}
    swap(a[p],a[q]);
  }
  vector<int> vc;
  long long res=0;
  for(auto &nx : a){vc.push_back(nx.first);}
  vc.push_back(1000000007);
  sort(vc.begin(),vc.end());
  int i=0;
  map<int,int> mp;
  for(auto &nx : a){
    i++;
    mp[nx.first]=i;
    int sa=nx.first;
    int sb=nx.second;
    if(sa>sb){swap(sa,sb);}
    if(sa!=sb){
      res+=(sb-sa);
      res-=search(sb,vc);
      res+=search(sa,vc);
    }
  }
  //cout << res << '\n';
  bit.clear();
  int cnt=0;
  for(auto &nx : a){
    int cn=mp[nx.second];
    res+=cnt;
    res-=sum(cn);
    add(cn,1);
    cnt++;
  }
  cout << res << '\n';
  return 0;
}