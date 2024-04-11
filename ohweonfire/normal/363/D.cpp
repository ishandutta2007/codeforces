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
using namespace std;
typedef long long ll;
int n,m,p[100002],b[100002],k,l,r;
ll a,ans;
bool chk(int x){
	 ll tmp=a;
	 for(int i=0;i<x;i++){
	 		 if(tmp+b[i]<p[x-i-1])return false;
	 		 if(b[i]<p[x-i-1])tmp-=p[x-i-1]-b[i];
	}
	return true;
}
int main(){
	scanf("%d%d%I64d",&n,&m,&a);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<m;i++)scanf("%d",p+i);
	sort(b,b+n);
	sort(p,p+m);
	reverse(b,b+n);
	l=0;
	r=min(n,m)+1;
	while(l+1<r){
				 k=(l+r)/2;
				 if(chk(k))l=k;else r=k;
				 //cout<<k<<' '<<l<<' '<<r<<endl;
	}
	for(int i=0;i<l;i++)ans+=p[i];
	ans-=a;
	if(ans<0)ans=0;
	printf("%d %I64d\n",l,ans);
	//system("pause");
	return 0;
}