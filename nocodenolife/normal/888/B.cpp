#include <bits/stdc++.h>
using namespace std;


int mod(int a)
{
	if(a<0)
		return -1*a;
	return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='L')
    		x-=1;
    	if(s[i]=='R')
    		x+=1;
    	if(s[i]=='U')
    		y+=1;
    	if(s[i]=='D')
    		y-=1;
    }
    int answer = n - mod(x) - mod(y);

    cout<<answer<<endl;

    return 0;
}