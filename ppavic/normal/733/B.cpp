#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
int mx = -1;
int a[100005];
int l,r;
int sm = 0;
int mi = -1;
int sol = 0;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&l,&r);
		a[i] = l-r;
		sm += a[i];
	}
	mi = abs(sm);
	for(int i = 0;i<n;i++){
		if(abs(0-(sm-a[i]+(a[i]*-1))) > mi){
			mi = abs(0-(sm-a[i]+(a[i]*-1)));
			sol = i+1;
		}	

	}
	printf("%d\n",sol);
	
	
}