#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int BT = 24;
const int N = (1<<BT);

int arr[N];
int n;
string s;

signed main()
{
   fast;
    
   cin >> n;
    
   f(i,n)  
   { 
       cin >> s;
       
       int num = 0;
       for(auto x : s) num|=(1LL<<(x-'a'));
       arr[num]++;
       for(auto x : s) arr[1LL<<(x-'a')]++;
       
       arr[(1LL<<(s[0]-'a'))|(1LL<<(s[1]-'a'))]--;
       arr[(1LL<<(s[0]-'a'))|(1LL<<(s[2]-'a'))]--;
       arr[(1LL<<(s[1]-'a'))|(1LL<<(s[2]-'a'))]--;
   }
    
   int res = 0;
    
   f(i,BT) f(j,N) 
       if(j & (1<<i)) 
          arr[j] += arr[j^(1<<i)];
       
   f(i,N) res^=(arr[i]*arr[i]);
    
   cout << res;
}