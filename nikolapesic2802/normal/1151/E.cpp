#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main()
{
	ll n,c=0;
	scanf("%lld",&n);
	vector<int> niz(n);
	for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
	for(int i=0;i<n;i++)
        c+=(ll)niz[i]*(n-niz[i]+1);
    int last=niz[0];
	for(int i=1;i<n;i++)
        c-=(ll)min(niz[i],niz[i-1])*(n-max(niz[i],niz[i-1])+1);
    printf("%lld\n",c);
    return 0;
}