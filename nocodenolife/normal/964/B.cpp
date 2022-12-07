#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,a,b,c,t;
    cin>>n>>a>>b>>c>>t;

    long long int answer = n*a;
    if(b<c)
    {
    	int diff = c-b;
    	for(int i=0;i<n;i++)
    	{
    		int rec;
    		cin>>rec;
    		answer += (t-rec)*diff;
    	}
    }
    cout<<answer<<endl;
    return 0;
}