#include<bits/stdc++.h>

using namespace std;

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    vector<int> v;
    for(int i=0;i<n;i++){if(s[i]=='*'){v.push_back(i);}}
    n=v.size();
    if(n==0){cout << "0\n";continue;}
    int mid=v[n/2];
    long long res=0;
    for(int i=0;i<n;i++){
      long long tg=mid+i-(n/2);
      res+=llzt(tg,(long long)v[i]);
    }
    cout << res << '\n';
  }
  return 0;
}