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

int mem[120];
int m;
int kol;

void alloc(int n){
	int l=0;
	for (int i=0;i<m;i++){
		if (mem[i]!=0)
			l=0;
		else {
			l++;
			if (l==n){
				++kol;
				for (int j=i-n+1;j<=i;j++)
					mem[j]=kol;
				printf("%d\n",kol);
				return;
			}
		}
	}
	printf("NULL\n");
}

void erase(int id){
	if (id==0)
	{
		printf("ILLEGAL_ERASE_ARGUMENT\n");
		return;
	}
	bool q=false;
	for (int i=0;i<m;i++)
		if (mem[i]==id){
			q=true;
			mem[i]=0;
		}
	if (!q)
		printf("ILLEGAL_ERASE_ARGUMENT\n");
	return;
}

void defragment(){
	int sdv=0;
	for (int i=0;i<m;i++)
		{
			if (mem[i]==0){
				sdv++;
				continue;
			}
			mem[i-sdv]=mem[i];
			if (sdv!=0)
				mem[i]=0;
		}
	return;
}



int main()
{
/*  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  int t;
  scanf("%d %d\n",&t,&m);
  kol=0;
  for (int i=0;i<t;i++){
  	string s;
  	getline(cin,s);
    	int par;
  	if (sscanf(s.data(),"alloc %d",&par)==1)
  		alloc(par);
  	else if (sscanf(s.data(),"erase %d",&par)==1)
  		erase(par);
  	else
  		defragment();
  }
  return 0;
}