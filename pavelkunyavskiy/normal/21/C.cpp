#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "C"

using namespace std;

typedef long long int64;
typedef long double ld;

int sum[110000];
int a[110000];

int main(){
	#ifdef LOCAL
		freopen(taskname".in","r",stdin);
		freopen(taskname".out","w",stdout);
	#endif
    int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sum[0]=a[0];
	for (int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];
	int sumall=sum[n-1];
	
	//cerr<<sumall<<endl;
	
	if (abs(sumall)%3!=0){
		printf("0\n");
		return 0;
	}
	
	int sum3=abs(sumall)/3;
	if (sumall<0)
		sum3*=-1;
	
	int64 kol=0;
	int tmp=0;	
	
	//cerr<<sum3<<" "<<sumall<<endl;
	
	for (int i=0;i<n-1;i++){
		if (sum[i]==2*sum3)
			kol+=tmp;
		if (sum[i]==sum3)
			tmp++;		
	}
    cout<<kol<<endl;
    return 0;
}