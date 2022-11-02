#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int n,w;
int a[111];

int main(){
  cin>>n>>w;
  int s = 0;
  for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
  if(w<=0 || w>s || n==1 && w!=a[0]) puts("No");
  else{
    if(n==1){
      puts("Yes");
      for(int i=0;i<a[0];i++){
	if(i) cout<<" ";
	cout<<"1 1";
      }
      puts("");
      return 0;
    }
    int mn = 0;
    for(int i=0;i<n;i++) if(a[mn] > a[i]) mn=i;
    if(w==1){
      if(a[mn]==1){
	puts("Yes");
	cout<<mn+1;
	for(int i=0;i<n;i++) 
	  if(mn!=i)
	    for(int j=0;j<a[i];j++)
	      printf(" %d %d",i+1,i+1);
	cout<<' '<<mn+1<<endl;
      }else{
	puts("No");
      }
    }else{
      puts("Yes");
      if(w>=a[mn]){
	cout<<mn+1;
	for(int i=0;i<n;i++)
	  if(i!=mn)
	    while(s!=w && a[i])
	      printf(" %d %d",i+1,i+1),a[i]--,s--;
	cout<<' '<<mn+1;
	for(int i=1;i<a[mn];i++)
	  cout<<' '<<mn+1<<' '<<mn+1;
	a[mn]=0;
	for(int i=0;i<n;i++)
	  while(a[i])
	    printf(" %d %d",i+1,i+1),a[i]--;
	puts("");
      }else{
	int j = (mn==1 ? 0 : 1);
	cout<<j+1;
	for(int i=0;i<n;i++)
	  if(i!=j && i!=mn)
	    while(a[i])
	      printf(" %d %d",i+1,i+1),a[i]--;
	while(a[mn]!=w-1)
	  cout<<' '<<mn+1<<' '<<mn+1,a[mn]--;
	cout<<' '<<j+1;
	cout<<' '<<mn+1;
	a[j]--;
	while(a[j])
	  cout<<' '<<j+1<<' '<<j+1,a[j]--;
	cout<<' '<<mn+1;
	a[mn]--;
	while(a[mn])
	  cout<<' '<<mn+1<<' '<<mn+1,a[mn]--;
	puts("");
      }   
    } 
  } 
  return 0;
}