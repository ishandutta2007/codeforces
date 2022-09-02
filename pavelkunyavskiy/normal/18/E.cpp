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

char a[500][500];

int kol[500][26][2];
int t[500][26][26];
int from[500][26][26][2];

int n,m;

const int inf=1<<25;

void PreCalc(){
	for (int i=0;i<n;i++)
		for (int j=0;j<26;j++)
			for (int k=0;k<m;k++)
				if (a[i][k]!=j+'a')
					kol[i][j][k%2]++;
}

void print(int i,int c1,int c2){	

	if (i==0){
		string tmp="";
		tmp+=(char)(c1+'a');
		tmp+=(char)(c2+'a');
		for (int j=0;j<m;j++)
			printf("%c",tmp[j%2]);
		printf("\n");
		return;
	}
	print(i-1,from[i][c1][c2][0],from[i][c1][c2][1]);
	string tmp="";
	tmp+=(char)(c1+'a');
	tmp+=(char)(c2+'a');
	for (int j=0;j<m;j++)
		printf("%c",tmp[j%2]);
	printf("\n");
	
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  scanf("%d %d",&n,&m);
  for (int i=0;i<n;i++)
  	for (int j=0;j<m;j++)
  		scanf(" %c ",&a[i][j]);
  
 	PreCalc();
 	
 	memset(t,1,sizeof(t));
 	
 	for (int i=0;i<26;i++)
 		for (int j=0;j<26;j++)
 			if (i!=j)
	 			t[0][i][j]=kol[0][i][0]+kol[0][j][1];
	 		else
	 			t[0][i][j]=inf;

	for (int i=0;i<n-1;i++)
		for (int j=0;j<26;j++)
			for (int k=0;k<26;k++)
				if (k!=j)
					for (int nj=0;nj<26;nj++)
						if (nj!=j)
							for (int nk=0;nk<26;nk++)
								if (nk!=k && nk!=nj){
									int nans=t[i][j][k]+kol[i+1][nj][0]+kol[i+1][nk][1];
									if (nans<t[i+1][nj][nk]){
										t[i+1][nj][nk]=nans;
										from[i+1][nj][nk][0]=j;
										from[i+1][nj][nk][1]=k;										
									}
								}
  int ans=inf;
  for (int i=0;i<26;i++)
  	for (int j=0;j<26;j++)
  		ans=min(ans,t[n-1][i][j]);
  		
  		
	printf("%d\n",ans);
  		
  for (int i=0;i<26;i++)
  	for (int j=0;j<26;j++)
  		if (t[n-1][i][j]==ans){

  			print(n-1,i,j);
  			return 0;
  		}

								
								
  return 0;
}