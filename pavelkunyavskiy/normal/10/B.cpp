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

int n;
int xc,yc;

int sum(int r){
	return r*(r+1)/2;
}

int sum(int l,int r){
	return sum(r)-sum(l-1);
}

int f(int x,int yl,int yr){
	int kol=yr-yl+1;
	int ans=abs(x-xc)*kol;
	if (yr<=yc)	
		return ans+sum(yc-yr,yc-yl);
	if (yl>=yc)
		return ans+sum(yl-yc,yr-yc);
	return ans+sum(yc-yl)+sum(yr-yc);
}

bool can[110][110][110];

void get(int x,int l,int r){
	cout<<x+1<<" "<<l+1<<" "<<r+1<<endl;
	for (int i=l;i<=r;i++)
		memset(can[x][i],false,sizeof(can[x][i]));
	for (int d=1;d<=l;d++){
		for (int i=d+1;i<=n;i++)
			can[x][l-d][i]=false;
	}
}

void find(int m){
	int ansx=-1;
	int ansy=-1;
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (can[i][j][m]){
				if (ansx==-1 || ans>f(i,j,j+m-1)){
					ansx=i;
					ansy=j;
					ans=f(i,j,j+m-1);
				}
			}
	if (ansx==-1)
		cout<<-1<<endl;
	else
		get(ansx,ansy,ansy+m-1);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int kol;
  cin>>kol>>n;
  xc=(n/2);
  yc=n/2;
  for (int i=0;i<n;i++)
  	for (int j=0;j<n;j++)
  		for (int k=0;k<=n;k++)
  			if (j+k-1<n)
  				can[i][j][k]=1;
  			else
	  			can[i][j][k]=0;
	for (int i=0;i<kol;i++){
		int m;
		scanf("%d",&m);
		find(m);
	}
  return 0;
}