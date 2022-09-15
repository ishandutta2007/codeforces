#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool used[200001];
int main()
{
   string s;cin>>s;
   int cnt=0;
   for (auto i:s) cnt+=(i=='a');
   cout<<min((2*cnt-1),(int)s.size());
   return 0;
}