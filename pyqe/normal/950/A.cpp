#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long lh,rh,w;
	
	scanf("%lld%lld%lld",&lh,&rh,&w);
	printf("%lld\n",min((lh+rh+w)/2,min(lh+w,rh+w))*2);
}