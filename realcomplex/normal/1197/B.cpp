#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 200009;
int p[N];
int main() {
 fastIO; 
 int n;
 cin >> n;
 int a;
 for(int i = 1;i <= n; i++){
  cin >> a;
  p[a] = i;
 }
 int l = p[n], r = p[n];
 for(int i = n - 1; i > 0; i --){
  if(p[i] == l - 1) l --;
  else if(p[i] == r + 1) r ++;
  else{
   cout << "no\n";
   return 0;
  }
 }
 cout << "yes";
 return 0;
}