#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int s;
    cin>>s;
    int prev=0;
    int answer=0;
    for(int i=1;i<n;i++)
    {
    	int k;
    	cin>>k;
    	if(k>s)
    	{
    		if(prev==-1)
    			answer++;
    		prev = 1;
    	}
    	else if(k<s)
    	{
    		if(prev==1)
    			answer++;
    		prev = -1;
    	}
    	else
    		prev = 0;
    	s = k;
    }

    cout<<answer;
    return 0;
}