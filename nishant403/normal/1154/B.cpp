#include <bits/stdc++.h>
using namespace std;

void nn()
{
cout << -1; 
exit(0);
}


int main()
{
int n,k;
cin >> n;
set<int> s;

for(int I=0;I<n;I++) 
{
cin >> k; s.insert(k);
}

if(s.size() > 3) nn();
vector<int> z;

for(auto j : s) z.push_back(j);

if(s.size()==2) 
{
if( (z[1]-z[0]) % 2 == 0) cout << (z[1]-z[0])/2;
else cout << z[1]-z[0];
}
else if (s.size()==3)
{
if(z[2]-z[1] != z[1]-z[0]) nn();
cout << z[1]-z[0];
}
else cout << 0;
}