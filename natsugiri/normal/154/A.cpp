#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;
int k,n;
string v[15];
string s;
int slv(int l,int r,string x){
  int a,b,i;
  a=b=0;
  for(i=l;i<r;i++){
    if(s[i]==x[0])a++;
    if(s[i]==x[1])b++;
  }
  return min(a,b);
}

  
int main(){
  int i,j,t;
  int ans=0;
  cin>>s>>k;
  n=s.size();
  for(i=0;i<k;i++)cin>>v[i];
  for(i=0;i<n;i++){
    for(j=0;j<k;j++){
      if(s[i]==v[j][0]||s[i]==v[j][1]){
	for(t=i+1;t<n;t++){
	  if(s[t]!=v[j][0]&&s[t]!=v[j][1])break;
	}
	ans+=slv(i,t,v[j]);
	i=t-1;
	break;
      }
    }
  }

  printf("%d\n",ans);
  return 0;
}