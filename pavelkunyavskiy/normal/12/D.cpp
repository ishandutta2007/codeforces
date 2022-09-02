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

const int maxn=500100;

struct dam{
	int par[3];
};


struct cmp{
int p;
bool operator()(const dam& a,const dam &b){
	if (a.par[p]!=b.par[p])
		return a.par[p]<b.par[p];
	return false;
}
cmp(int P){p=P;}
};

dam a[maxn];
int n;

void sjat(int p){
	sort(a,a+n,cmp(p));
	int ptr,dptr;
	ptr=dptr=0;
	int v=0;
	for (;ptr<n;){
		int tmp=a[ptr].par[p];
		for (;ptr<n && a[ptr].par[p]==tmp;ptr++)
			a[ptr].par[p]=v;
		v++;
	}
	for (int i=0;i<n;i++)
		a[i].par[p]=v-a[i].par[p]-1;
}

int fen[maxn];

const int inf=2*maxn;

int mv(int r){
	int ans=inf;
	for (;r!=-1;r=(r&(r+1))-1){
		ans=min(ans,fen[r]);
	}
	return ans;
}

void upd(int r,int val){
	for (;r<n;r=(r|(r+1))){
		fen[r]=min(fen[r],val);
	}
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  scanf("%d",&n);
  for (int p=0;p<3;++p)
  for (int i=0;i<n;i++){
  	scanf("%d",&a[i].par[p]);
  }
  sjat(2);
  sjat(1);
  sjat(0);
  sort(a,a+n,cmp(0));
  for (int i=0;i<n;i++)
  	fen[i]=inf;
  int pt1,pt2;
  pt1=pt2=0;
  int kol=0;
  for (;pt2<n;){
  	for (;pt1<n && a[pt1].par[0]==a[pt2].par[0];pt1++)
  		if (a[pt1].par[1]!=0)
	  		if (mv(a[pt1].par[1]-1)<a[pt1].par[2]){
  	  		kol++;
	   		}
  	for (;pt2<pt1;pt2++)
  		upd(a[pt2].par[1],a[pt2].par[2]);
  }	
  cout<<kol<<endl;
  return 0;
}