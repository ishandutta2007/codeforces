#include<bits/stdc++.h>

// using namespace std;
//
// int n;
//
// int main(){
//   for(n=2;;n++){
//     vector<int> p(n-1);
//     for(int i=0;i<(n-1);i++){p[i]=i+1;}
//     set<string> res_st;
//     do{
//       string s;
//       for(int i=0;i<n;i++){s.push_back('+');}
//       vector<int> wall(n+1,0);
//       wall[0]=1;
//       wall[n]=1;
//       for(auto &nx : p){
//         int tg=nx;
//         while(wall[tg]==0){
//           s[tg-1]=('+'+'-'-s[tg-1]);
//           tg--;
//         }
//         tg=nx;
//         while(wall[tg]==0){
//           s[tg]=('+'+'-'-s[tg]);
//           tg++;
//         }
//         wall[nx]=1;
//       }
//       res_st.insert(s);
//     }while(next_permutation(p.begin(),p.end()));
//     for(auto &nx : res_st){cout << nx << '\n';}
//     cout << '\n';
//   }
//   return 0;
// }

using namespace std;

multiset<long long> pl_set;
long long zero_cnt=0;
multiset<long long> mi_set;

void ins(long long x){
  if(x>0){pl_set.insert(x);}
  else if(x<0){mi_set.insert(-x);}
  else{zero_cnt++;}
}

void era(long long x){
  if(x>0){pl_set.erase(pl_set.find(x));}
  else if(x<0){mi_set.erase(mi_set.find(-x));}
  else{zero_cnt--;}
}

long long plval(long long x){
  if(pl_set.size()<x){return 8e18;}
  auto it=pl_set.begin();
  long long res=0;
  for(int i=0;i<x;i++){
    res+=(*it);
    it++;
  }
  return res;
}

long long mival(long long x){
  if(mi_set.size()<x){return 8e18;}
  auto it=mi_set.begin();
  long long res=0;
  for(int i=0;i<x;i++){
    res+=(*it);
    it++;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int plm3;
  if(n%3==0){plm3=2;}
  if(n%3==1){plm3=1;}
  if(n%3==2){plm3=0;}
  vector<long long> a(n);

  long long opt=0;
  for(auto &nx : a){
    cin >> nx;
    opt+=abs(nx);
    ins(nx);
  }

  if(n==1){
    cout << a[0] << '\n';
    return 0;
  }

  if(zero_cnt>6){
    long long needless=((zero_cnt-6)/3)*3;
    zero_cnt-=needless;
  }
  
  long long minlost=8e18;
  for(int p=1;p<n;p++){
    // cerr << p << '\n';
    era(a[p-1]);
    era(a[p]);
    long long curlost;

    curlost=0;
    if(a[p-1]<0){curlost-=a[p-1];}
    if(a[p]<0){curlost-=a[p];}
    for(int i=0;i<=zero_cnt;i++){
      for(int j=0;j<i;j++){pl_set.insert(0);}
      for(int j=i;j<zero_cnt;j++){mi_set.insert(0);}
      int rempl=(plm3+(3-2))%3;
      int curpl=(pl_set.size()%3);
      long long lost=curlost+min(plval((curpl-rempl+3)%3),mival((3-curpl+rempl)%3));
      minlost=min(minlost,lost);
      pl_set.erase(0);
      mi_set.erase(0);
    }

    curlost=0;
    if(a[p-1]>0){curlost+=a[p-1];}
    if(a[p]>0){curlost+=a[p];}
    for(int i=0;i<=zero_cnt;i++){
      for(int j=0;j<i;j++){pl_set.insert(0);}
      for(int j=i;j<zero_cnt;j++){mi_set.insert(0);}
      int rempl=(plm3)%3;
      int curpl=(pl_set.size()%3);
      long long lost=curlost+min(plval((curpl-rempl+3)%3),mival((3-curpl+rempl)%3));
      minlost=min(minlost,lost);
      pl_set.erase(0);
      mi_set.erase(0);
    }

    ins(a[p-1]);
    ins(a[p]);
  }
  cout << opt-2*minlost << '\n';
  return 0;
}