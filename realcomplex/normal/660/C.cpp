#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
int t[N];

int main(){
   fastIO;
   int n, k;
   cin >> n >> k;
   for(int i = 0 ; i < n ; i ++ ) cin >> t[i];
   int l = 0;
   int s = 0;
   int cl=0,cr=-1,mx=t[0];
   for(int i = 0 ; i < n; i ++ ){
	s += 1-t[i];
	while(s > k){
	   s-=1-t[l++];
        }
	if(i - l + 1 >= mx){
           mx = i - l  + 1;
           cl = l;
           cr = i;
	}
   }
   cout << mx << "\n";
   for(int i = 0 ; i < n; i ++ ){
      if(i >= cl && i <= cr)
	cout << 1 << " ";
      else 
	cout << t[i] << " ";
   }
   return 0;
}