#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100100
using namespace std;
double n,m,k,ans=1,ep[N];
int main(){
	int i;
	scanf("%lf%lf%lf",&n,&m,&k);
	if(k+n<m)
	{
		printf("0\n");
		return 0;
	}
	if(k>=m)
	{
		printf("1\n");
		return 0;
	}
	ep[0]=ep[1]=0;
	for(i=2;i<N;i++)
	{
		ep[i]=ep[i-1]+logl(i);
	}
	//cout<<ep[(int)n]<<" "<<ep[(int)m]<<" "<<ep[(int)(n+k+1)]<<" "<<ep[(int)(m-k-1)]<<endl;
	//cout<<ep[3]<<endl;
	ans=ep[(int)n]+ep[(int)m]-ep[(int)(n+k+1)]-ep[(int)(m-k-1)];
	ans=expl(ans);
	printf("%.12f\n",1-ans);
	return 0;
}