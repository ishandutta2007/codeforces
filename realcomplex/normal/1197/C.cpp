#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main() {
 fastIO; 
 int n,k;
 cin >> n >> k;
 int ans = 0;
 int a[n];
 vector<int>t;
 for(int i = 0; i < n; i ++){
  cin >> a[i];
  if(i)t.push_back(a[i-1]-a[i]);
 }
 
 ans += a[n-1];
 ans -= a[0];
 sort(t.begin(),t.end());
 for(int i = 1; i < k; i ++){
   ans += t[i-1];
 }
 cout << ans;
 return 0;
}