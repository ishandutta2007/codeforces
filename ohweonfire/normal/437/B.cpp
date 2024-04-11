#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <numeric>
#define ff first
#define ss second
#define pb push_back
const int maxn=100005;
int n,limit;
int lowbit[maxn],num[maxn];
int sum;
bool use[maxn];
bool cmp(int i,int j){return lowbit[i]>lowbit[j];}
void init(){
	 sum=n;
	 for(int i=0;i<maxn;i++)num[i]=i+1;
	 int res=1;
	 do{
	 	 for(int i=res;i<=n;i+=res*2){
		 		 lowbit[i]=res;
		 		 num[--sum]=i;
		}
	 	 res*=2;
	}while(res<=n);
}
int main(){
	scanf("%d%d",&limit,&n);
	init();
	int cnt=0;
	for(int i=0;i<n;i++)
	{
	 		if(limit>=lowbit[num[i]]){use[num[i]]=true;limit-=lowbit[num[i]];cnt++;}
	 		if(!limit)break;
	}
	if(limit){printf("-1");return 0;}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(use[i])printf("%d ",i);
	return 0;
}