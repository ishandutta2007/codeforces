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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int t;
char str[100];

int fmax(int l,int r){
  int re=-1,i,pos;
  for(i=l;i<r;i++)
    if(re<str[i]-'0'){
      re=str[i]-'0';
      pos=i;
    }
  return pos;
}

int main(){
  int i,j,k,n;
  scanf("%s %d",str,&t);
  n=strlen(str);
 // cout<<str<<endl;
  for(i=0;i<n;i++){
    int tmp=fmax(i,min(n,i+t+1));
  //  cout<<"t:"<<t<<","<<tmp<<endl;
    for(j=tmp;j>i;j--){
      swap(str[j],str[j-1]);
      t--;
    }//cout<<str<<endl;
    if(t==0)break;
  }
  cout<<str<<endl;
  return 0;
}