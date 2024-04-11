#include <bits/stdc++.h>
using namespace std;

//manacher algorithm
//http://snuke.hatenablog.com/entry/2014/12/02/235837

//longest palindrome(length:odd)
//if you want to find the answer for even palindrome,
//you can use dummy letter.
//ex. $a$b$c$c$b$a$
void manacher(char s[],int arr[],int l){
  int i,j,k;
  i=0;j=0;
  while(i<l){
    while((i-j)>=0 && (i+j)<l){
      if(s[i-j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    k=1;
    while((i-k)>=0 && (i+k)<l){
      if(k+arr[i-k]>=arr[i]){break;}
      arr[i+k]=arr[i-k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }
}

int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int i,j,n,m,k,earr[2097152],b,c,h,w,r=0,l,t;
  int st,fi,kl;
  char s[2097152],ks[2097152],es[2097152];
  scanf("%d",&t);
  while(t>0){
    t--;
    scanf("%s",s);
    l=strlen(s);
    st=0;fi=l-1;
    for(i=0;i<l;i++){
      if(s[st]!=s[fi]){break;}
      st++;fi--;
    }
    if(st==l){printf("%s\n",s);continue;}
    for(i=st;i<=fi;i++){
      ks[i-st]=s[i];
    }
    kl=fi-st+1;
    for(i=0;i<kl;i++){
      es[2*i]='$';
      es[2*i+1]=ks[i];
    }
    es[2*kl]='$';
    es[2*kl+1]=0;
    //printf("<%s>\n",es);
    manacher(es,earr,2*kl+1);
    r=-1;c=-1;
    for(i=0;i<2*kl+1;i++){
      //printf("%d",earr[i]);
      if((i-earr[i]+1)!=0 && (i+earr[i])!=2*kl+1){continue;}
      if(c<earr[i]){
        c=earr[i];
        r=i;
      }
    }//printf(":%d %d\n",r,c);
    for(i=0;i<st;i++){
      printf("%c",s[i]);
    }
    for(i=r-c+1;i<r+c;i++){
      if(es[i]!='$'){printf("%c",es[i]);}
    }
    for(i=fi+1;i<l;i++){
      printf("%c",s[i]);      
    }
    printf("\n");
  }
  return 0;
}