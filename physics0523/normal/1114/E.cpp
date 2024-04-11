#include<bits/stdc++.h>

using namespace std;

int que;
int ask(int x){
  que++;
  cout << "? " << x << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

int g(int x){
  que++;
  cout << "> " << x << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  que=0;

  int n;
  cin >> n;
  int st=0,fi=1000000000;
  while(st<=fi){
    int te=(st+fi)/2;
    if(g(te)==1){st=te+1;}
    else{fi=te-1;}
  }

  vector<int> lis={st};
  vector<int> a(n);
  for(int i=0;i<n;i++){a[i]=i;}
  shuffle(a.begin(),a.end(),engine);
  while(que<60 && !a.empty()){
    int od=a.back();a.pop_back();
    lis.push_back(ask(od+1));
  }
  sort(lis.begin(),lis.end());
  int d=lis.back()-lis[0];
  for(int i=1;i<lis.size();i++){
    d=gcd(d,lis[i]-lis[i-1]);
  }

  cout << "! " << st-d*(n-1) << " " << d << "\n";
  fflush(stdout);
  return 0;
}