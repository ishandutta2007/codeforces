#include<bits/stdc++.h>

using namespace std;

//z-algorithm
//https://snuke.hatenablog.com/entry/2014/12/03/214243

//longest prefix between S & s_i s_i+1 ... s_l
vector<int> z_algorithm(string s){
  int i,j,k,l;
  l=s.size();
  vector<int> arr(l);
  arr[0]=l;
  i=1;j=0;
  while(i<l){
    while((i+j)<l){
      if(s[j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    if(j==0){i++;continue;}
    k=1;
    while((i+k)<l){
      if(k+arr[k]>=arr[i]){break;}
      arr[i+k]=arr[k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }
  return arr;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  int n;
  cin >> n;
  vector<int> rig(l,l-1);
  for(int i=0;i<n;i++){
    string t;
    cin >> t;
    int tl=t.size();
    string zs=t+s;
    vector<int> z=z_algorithm(zs);
    for(int i=0;i<l;i++){
      if(z[tl+i]>=tl){rig[i]=min(rig[i],i+tl-2);}
    }
  }
  for(int i=l-2;i>=0;i--){rig[i]=min(rig[i],rig[i+1]);}
  int rl=0,rst=0;
  for(int i=0;i<l;i++){
    int cl=rig[i]-i+1;
    if(rl<cl){
      rl=cl;
      rst=i;
    }
  }
  cout << rl << ' ' << rst << '\n';
  return 0;
}