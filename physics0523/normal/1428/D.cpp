#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  int cnt[4]={0};
  vector<int> key(n+1,0);
  vector<pair<int,int>> res;
  queue<int> sta[4];
  vector<int> spk(n+1,-1);
  for(int i=n;i>=1;i--){
    if(a[i]==0){continue;}
    cnt[a[i]]++;
    if(a[i]==1){
      sta[1].push(i);
      key[i]=i;
      spk[i]=0;
    }
    else if(a[i]==2){
      if(sta[1].empty()){cout << "-1\n";return 0;}
      int nk=sta[1].front();
      spk[nk]=1;
      key[i]=nk;
      sta[1].pop();
      sta[2].push(nk);
    }
    else{
      if(!(sta[3].empty())){
        //cout << "ok\n";
        int nk=sta[3].front();
        spk[nk]++;
        key[i]=nk;
      }
      else if(!(sta[2].empty())){
        int nk=sta[2].front();
        spk[nk]=2;
        key[i]=nk;
        sta[2].pop();
        sta[3].push(nk);
        //cout << "ok\n";
      }
      else if(!(sta[1].empty())){
        int nk=sta[1].front();
        spk[nk]=2;
        key[i]=nk;
        a[nk]=2;
        sta[1].pop();
        sta[3].push(nk);
        //cout << "ok\n";
      }
      else{cout << "-1\n";return 0;}
    }
    //if(!(cnt[1]>=cnt[2] && cnt[2]>=cnt[3])){cout << "-1\n";return 0;}
  }
  int pt=1;
  vector<bool> dfl(n+1,false);
  vector<int> d(n+1,0);
  for(int i=n;i>=1;i--){
    //cout << spk[i] << ' ' << key[i] << '\n';
    if(spk[i]==-1){continue;}
    int cspk=spk[i];
    if(spk[i]>=1){dfl[i]=true;}
    d[i]=max(0,spk[i]-1);
    spk[i]=pt;pt+=(cspk+1);
  }
  for(int i=1;i<=n;i++){
    if(a[i]==0){continue;}
    int pos=spk[key[i]];
    if(d[key[i]]>0){
      res.push_back(make_pair(pos,i));
      res.push_back(make_pair(pos+1,i));
      spk[key[i]]++;
      d[key[i]]--;
      continue;
    }
    //cout << pos << '\n';
    if(dfl[key[i]]==false){pos--;}
    if(a[i]!=1){res.push_back(make_pair(pos,i));}
    if(a[i]!=3){res.push_back(make_pair(pos+1,i));}
  }
  int nn=res.size();
  int v=0;
  for(int i=0;i<nn;i++){
    v=max(res[i].first,v);
  }
  if(v>n){
    vector<pair<int,int>> nres;
    for(int i=0;i<nn;i++){
      if(res[i].first==1){continue;}
      res[i].first--;
      nres.push_back(res[i]);
    }
    res.swap(nres);
  }
  cout << res.size() << '\n';
  for(auto x:res){
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}