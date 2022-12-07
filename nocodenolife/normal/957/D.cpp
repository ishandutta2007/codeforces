#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int days[n];
    int m[n];
    int t;
    for(int i=0;i<n;i++)
    {
    	cin>>t;
    	m[i] = t;
    	t++;
    	days[i] = t;
    }

    for(int i=1;i<n;i++)
    {
    	if(days[i]<days[i-1])
    		days[i] = days[i-1];
    }
    for(int i=n-1;i>0;i--)
    {
        if(days[i]>days[i-1]+1)
    	{
    		days[i-1] = days[i] - 1;
    	}
    }
    long long int answer = 0;
    for(int i=0;i<n;i++)
    {
    	answer+= days[i] - m[i] -1;
    }

    cout<<answer<<endl;

    return 0;
}