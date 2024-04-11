#include<bits/stdc++.h>

using namespace std;

vector<long long> divi(long long x){
  vector<long long> res;
  for(long long i=1;i*i<=x;i++){
    if(x%i==0){
      res.push_back(i);
      if(i*i!=x){res.push_back(x/i);}
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;

  long long g;
  for(int i=0;i<n;i++){
    long long v;
    cin >> v;
    v--;
    while(v%2==0){v/=2;}
    if(i){g=gcd(g,v);}
    else{g=v;}
  }
  long long res=0;
  vector<long long> dv=divi(g);
  for(auto &nx : dv){
    long long cnx=nx;
    while(m-cnx>=0){
      res+=(m-cnx);
      cnx*=2;
    }
  }
  cout << res << '\n';
  return 0;
}

// exp
// #include<bits/stdc++.h>
//
// using namespace std;
//
// int main(){
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int p,q,m;
//   cin >> p >> q >> m;
//   vector<vector<int>> fl(m,vector<int>(m,0));
//   fl[p][q]=1;
//   while(1){
//     bool fin=true;
//     for(int i=1;i<m-1;i++){
//       for(int j=1;j<m-1;j++){
//         if(fl[i][j]==1 && fl[i+1][j+1]==0){
//           fin=false;
//           fl[i+1][j+1]=1;
//         }
//       }
//     }
//     for(int i=1;2*i<m;i++){
//       for(int j=1;2*j<m;j++){
//         if(fl[2*i][2*j]==1 && fl[i][j]==0){
//           fin=false;
//           fl[i][j]=1;
//         }
//       }
//     }
//     for(int i=1;i<m;i++){
//       for(int j=1;j<m;j++){
//         for(int k=1;k<m;k++){
//           if(fl[i][j]==1 && fl[j][k]==1 && fl[i][k]==0){
//             fin=false;
//             fl[i][k]=1;
//           }
//         }
//       }
//     }
//     if(fin){break;}
//   }
//   for(int i=1;i<m;i++){
//     for(int j=1;j<m;j++){
//       cout << fl[i][j];
//     }cout << '\n';
//   }
//   return 0;
// }