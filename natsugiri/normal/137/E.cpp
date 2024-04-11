#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200010][2];

bool isvowel(char c){
  char vowel[]="AOEUIaoeui";
  int i;
  for(i=0;i<10;i++){
    if(c==vowel[i])return 1;
  }
  return 0;
}

int main(){
  int i,j,n,k,h;
  string s;
  cin>>s;
  n=s.size();
  for(i=0;i<n;i++){
    if(isvowel(s[i]))s[i]='v';
    else s[i]='c';
  }
  for(i=0;i<=n;i++)a[i][0]=a[i][1]=0;
  for(i=0;i<n;i++){
    if('v'==s[i]){
      if(i==0)a[i][0]=0,a[i][1]=0;
      else{
	k=i-a[i-1][0];
	h=a[i-1][1];
	if(h>0){
	  a[i][0]=i+1;
	  a[i][1]=h-1;
	  continue;
	}
	for(j=k;j<=i;j++){
	  if('v'==s[j])h++;
	  else h-=2;
	  if(h==1){
	    break;
	  }
	}
	a[i][0]=i-j;
	a[i][1]=0;
      }
    }else{
      if(i==0)a[i][0]=1,a[i][1]=2;
      else if(a[i-1][1]>0)a[i][0]=i+1,a[i][1]=a[i-1][1]+2;
      else{
	k=i-a[i-1][0];
	h=a[i-1][1]+2;
	for(j=k-1;j>=0;j--){
	  if('v'==s[j])h--;
	  else h+=2;
	  if(h==0)break;
	}
	if(j<0)j++;
	a[i][0]=i-j+1;
	a[i][1]=h;
	if(j>0){
	  a[i][0]+=a[j-1][0];
	  a[i][1]+=a[j-1][1];
	}
	  
      }
    }
  }
  k=h=0;
  for(i=0;i<=n;i++){
    //cout<<a[i][0]<<' '<<a[i][1]<<endl;
    if(a[i][0]>k){
      k=a[i][0];
      h=0;
    }
    if(a[i][0]==k)h++;
  }
  if(k==0){
    puts("No solution");
  }else{
    printf("%d %d\n",k,h);
  }
}