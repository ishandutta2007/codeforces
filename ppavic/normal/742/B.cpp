#include <cstdio>
#include <algorithm>

using namespace std;

int n,x,tmp;
int rem[300005];
long long int sol = 0;

int main(){
	scanf("%d %d",&n,&x);
	for(int i = 0;i<n;i++){
		scanf("%d",&tmp);
		sol += rem[tmp^x];
		rem[tmp]++;
	}
	printf("%I64d\n",sol);
}