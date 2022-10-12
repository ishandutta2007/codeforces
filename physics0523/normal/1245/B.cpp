#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,r,p,s;
    cin >> n;
    string a,b;
    cin >> r >> p >> s;
    cin >> a;
    for(int i=0;i<n;i++){b.push_back('-');}
    int cnt=0;
    for(int i=0;i<n;i++){
      if(a[i]=='R' && p>0){cnt++;b[i]='P';p--;}
      else if(a[i]=='P' && s>0){cnt++;b[i]='S';s--;}
      else if(a[i]=='S' && r>0){cnt++;b[i]='R';r--;}
    }
    for(int i=0;i<n;i++){
      if(b[i]!='-'){continue;}
      if(r>0){b[i]='R';r--;}
      else if(p>0){b[i]='P';p--;}
      else if(s>0){b[i]='S';s--;}
    }
    if(cnt<(n/2)+(n%2)){cout << "NO\n";}
    else{
      cout << "YES\n";
      cout << b << '\n';
    }
  }
  return 0;
}