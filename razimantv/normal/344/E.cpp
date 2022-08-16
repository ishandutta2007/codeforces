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

int N,M;
long long head[100000],track[100000];

bool work(long long t)
{
  for(int i=0,j=0;i<N;i++)
  {
    int k=j;
    while((k<M)&&((min(abs(head[i]-track[j]),abs(head[i]-track[k]))+track[k]-track[j])<=t))k++;
    if(k==M)return true;
    j=k;
  }
  return false;
}

int main()
{
  cin>>N>>M;
  for(int i=0;i<N;i++)
  {
    cin>>head[i];
  }
  for(int i=0;i<M;i++)
  {
    cin>>track[i];
  }

  long long start=-1,end=10000000000000000ll,mid;
  while(end-start>1)
  {
    mid=(start+end)>>1;
    if(work(mid))end=mid;
    else start=mid;
  }
  cout<<end<<endl;
  return 0;
}