#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	int n;
 	cin>>n;
 	string s;
 	cin>>s;

 	int answer=0;

 	if(s[0]=='?'|| s[n-1]=='?')
 	{
 		answer=1;
 	}

 	for(int i=1;i<n-1;i++)
 	{
 		if(s[i]=='?')
 		{
 			if(s[i-1]==s[i+1])
 				answer=1;
 			else if(s[i-1]=='?'||s[i+1]=='?')
 				answer=1;
 		}
 		else
 		{
			if(s[i]==s[i+1] || s[i]==s[i-1])
 			{
 				cout<<"No"<<endl;
 				return 0;
 			}
 		}
 	}

 	if(answer==1)
 		cout<<"Yes";
 	else
 		cout<<"No";
 	

    return 0;
}