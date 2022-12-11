#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int AL = 26;
map<ll, int> cnt[AL];

int main(){
  fastIO;
  ll x[AL];
  for(int i = 0;i < AL;i ++ )
    cin >> x[i];
  string s;
  cin >> s;
  ll sum=0,las=0;
  ll ans = 0;
  for(char v : s){
    las=sum;
    ans += cnt[v - 'a'][las];
    sum += x[v-'a'];
    cnt[v-'a'][sum]++;
  }
  cout << ans;
  return 0;
}