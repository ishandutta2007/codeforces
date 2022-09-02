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

int64 a[5010];
int num[5010];
int n,n1;

int64 t[5010];
int64 t1[5010];

bool cmp(int f,int s){
	return a[f]<a[s];
}

bool cmp_ravn(int f,int s){
	return a[f]==a[s];
}

bool bet(int i,int j){
	if (j==n1)
		return false;
	int64 tec=t[j]+abs(a[num[j]]-a[i]);
	int64 will=t[j+1]+abs(a[num[j+1]]-a[i]);
	return will<tec;	
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  cin>>n;
  for (int i=0;i<n;i++)
  {
  	cin>>a[i+1];
  	num[i+1]=i+1;
  }
  sort(num+1,num+n+1,cmp);
  n1=unique(num+1,num+n+1,cmp_ravn)-(num+1);
  setval(t,0);
 	for (int i=1;i<=n;i++){
 		int ptr=1;
 		for (int j=1;j<=n;j++)
 			{

 				for (;ptr<j && bet(i,ptr);ptr++);
 				//cerr<<i<<" "<<j<<" "<<ptr<<endl;
 				t1[j]=t[ptr]+abs(a[num[ptr]]-a[i]);
 			}
 		memcpy(t,t1,sizeof(t));
 	}
 	cout<<t[n]<<endl;
  return 0;
}