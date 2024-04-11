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

string s;
string a,b;

bool check(){
  int n=s.size();
  int m=a.size();
  int k=b.size();
  bool fra=false,frb=false;
  for (int i=0;i<n;i++){
		if (!fra)  	
		{
			bool q=true;
			for (int j=0;j<m;j++)
				if (s[i+j]!=a[j])
				{
					q=false;
					break;
				}
			if (q){
				fra=true;
				i+=m-1;
			}
		}
		else {
				bool q=true;
				for (int j=0;j<k;j++)
					if (s[i+j]!=b[j])
					{		
						q=false;
						break;
					}		
				if (q){
					frb=true;
					break;
				}
		}
  }
	return fra && frb;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  getline(cin,s);
  getline(cin,a);
  getline(cin,b);
  bool f=check();
  reverse(s.begin(),s.end());
  bool s=check();
  if (f && s)
  	printf("both\n");
  else if (f)
  	printf("forward\n");
  else if (s)
  	printf("backward\n");
  else
  	printf("fantasy\n");
  return 0;
}