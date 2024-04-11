#include <bits/stdc++.h>
using namespace std;
const int L=22,N=1<<L;
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> num(N,-1),a(n);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]),num[(N-1)^a[i]]=a[i];
    for(int i=0;i<22;i++)
        for(int x=0;x<N;x++)
            if((x&(1<<i))==0)
                num[x]=max(num[x],num[x^(1<<i)]);
    for(int i=0;i<n;i++)
        printf("%i ",num[a[i]]);
    return 0;
}