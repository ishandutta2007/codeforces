#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define For(i,a,b) for(int i=a;i<=(int)(b);i++)
#define Ford(i,a,b) for(int i=a;i>=(int)(b);i--)
using namespace std;
int n,k;
string strs[101];
string goal;
int small=0,eaqal=0;
void init(){
	scanf("%d%d",&n,&k);
	For(i,1,n)
		cin>>strs[i];
	cin>>goal;
}
int main(){
	init();
	int glen=goal.length();
	For(i,1,n){
		int nlen=strs[i].length();
		if(nlen<glen)small++;
		if(nlen==glen)eaqal++;
	}
	int ans1=small+small/k*5+1;
	int ans2=small+eaqal+(small+eaqal-1)/k*5;
	printf("%d %d",ans1,ans2);
	return 0;
}