#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long int n,u;
    cin>>n>>u;

    long double eta = -1;
    long int states[n];
    for(int i=0;i<n;i++)
    {
    	cin>>states[i];
    }


    for(int i=0;i<n-2;i++)
    {
    	long int ei = states[i];
    	long int ej = states[i+1];
    	long int max = ei+u;
    	long int ek = *(upper_bound(states, states+n, max) - 1);
    	if(ek!=ei && ek!=ej && ej!=ei)
    	{
    		long double ans = (ek-ej+0.0)/(ek-ei+0.0);
    		if(ans>eta)
    			eta = ans;
    	}
    	
    }
    cout<<std::setprecision (17)<<eta<<endl;
    return 0;
}