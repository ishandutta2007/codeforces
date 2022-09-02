#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

const int maxn=5*1000000+100;

int p[2*maxn];
bool pal[maxn];
int kpal[maxn];
char s[2*maxn];


int main()
{
 /* #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  gets(s);
  int n=strlen(s);
  s[n]='$';
  for (int i=n-1;i>=0;i--)
  	s[2*n-i]=s[i];
  p[0]=0;
  int n2=2*n+1;
  for (int i=1;i<n2;i++){
  	int j=p[i-1];
  	for (;j!=0 && s[j]!=s[i];j=p[j-1]);
  	if (s[j]==s[i])
  		j++;
  	p[i]=j;
  }
  for (int i=p[n2-1];i!=0;i=p[i-1])
  	pal[i-1]=true;
  kpal[0]=1;
  int64 ans=1;
  for (int i=1;i<n;i++)
  {
  	if (pal[i])
  		kpal[i]=kpal[((i+1)>>1)-1]+1;
  	else
  		kpal[i]=0;
  	ans+=kpal[i];
//  	cerr<<pal[i]<<" "<<kpal[i]<<endl;
  }
  cout<<ans<<endl;		
  return 0;
}