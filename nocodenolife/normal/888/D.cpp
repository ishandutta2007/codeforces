#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n, k;
    cin>>n>>k;
    long long int answer = 0;
    if(k>=1)
    {
    	answer+=1;
    }
    if(k>=2)
    {
    	answer += n * (n-1) / 2;
    }
    if(k>=3)
    {
    	answer += (n*(n-1)*(n-2)/3);
    }
    if(k>=4)
    {
    	answer+= (n*(n-1)*(n-2)*(n-3)/8)*3;
    }

    cout<<answer<<endl;

    return 0;
}