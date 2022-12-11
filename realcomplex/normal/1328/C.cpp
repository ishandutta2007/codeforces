#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a, b;
    int mx = 0;
    for(int i = 0 ; i < s.size(); i ++ ){
      if(s[i] == '2'){
        if(mx == 0){
          a.push_back('1');
          b.push_back('1');
        }
        else{
          a.push_back('0');
          b.push_back('2');
        }
      }
      else if(s[i] == '1'){
        if(mx == 0){
          a.push_back('1');
          b.push_back('0');
          mx = 1;
        }
        else{
          a.push_back('0');
          b.push_back('1');
        }
          
      }
      else{
        a.push_back('0');
        b.push_back('0');
      }
    }
    cout << a << "\n" << b << "\n";
  }
  return 0;
}