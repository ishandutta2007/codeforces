# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

long long ans(long long num,long long den)
{
  if(den==1)return num;
  else if(num==1)return den;
  if(num>den)return num/den+ans(num%den,den);
  else return den/num+ans(num,den%num);
}

int main()
{
  long long a,b;
  cin>>a>>b;
  cout<<ans(a,b)<<endl;
  return 0;
}