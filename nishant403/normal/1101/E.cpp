#include <bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n; 
cin >> n;
long l=-1,w=-1;
char c;
long a,b;
//I assume l is shorter and w is bigger 
while(n--)
{
 cin >> c >> a >> b;
  if(a>b) swap(a,b);
  
 if(c=='+')
 {
    
    l=max(l,a);
    w=max(w,b);
 }
    else if(a>=l && b>=w) cout << "YES\n";
    else cout <<"NO\n";

    
}
return 0;
}