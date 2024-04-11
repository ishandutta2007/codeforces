#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;

char str[112345],xyz[]="xyz";
int cnt[3][112345];

int main(){
  int i,j,len;
  scanf("%s",str);
  len=strlen(str);
  for(i=0;i<len;i++){
    for(j=0;j<3;j++){
      cnt[j][i+1]=cnt[j][i]+(str[i]==xyz[j]);
  //    cout<<cnt[j][i]<<" ";
    }//cout<<endl;
  }

  int n,l,r,cntxyz[3];
  bool f=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    f=0;
    scanf("%d %d",&l,&r);
    for(j=0;j<3;j++)
      cntxyz[j]=cnt[j][r]-cnt[j][l-1];
    sort(cntxyz,cntxyz+3);
 //   for(j=0;j<3;j++)cout<<cntxyz[j]<<" ";
  //  cout<<endl;
    f|=(cntxyz[0]==cntxyz[1] && cntxyz[1]==cntxyz[2]);
    f|=(cntxyz[0]==cntxyz[1] && 1+cntxyz[1]==cntxyz[2]);
    f|=(1+cntxyz[0]==cntxyz[1] && cntxyz[1]==cntxyz[2]);
    f|=r-l+1<3;
    printf((f?"YES\n":"NO\n"));
  }
    return 0;
}