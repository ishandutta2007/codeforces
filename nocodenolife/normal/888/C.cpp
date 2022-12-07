#include <bits/stdc++.h>
using namespace std;

int check(int k, string s)
{
	int fin[26] = {0};
	int temp[26] = {0};
	for(int i=0;i<k;i++)
	{
		temp[(int)(s[i] - 'a')]++;
	}
	for(int i=0;i<26;i++)
	{
		if(temp[i]>0)
			fin[i]++;
	}
	for(int i=0;i<s.length()-k;i++)
	{
		temp[(int)(s[i] - 'a')]--;
		temp[(int)(s[i+k] - 'a')]++;
		for(int i=0;i<26;i++)
		{
			if(temp[i]>0)
				fin[i]++;
		}
	}
	int req = s.length()-k+1;
	for(int i=0;i<26;i++)
	{
		if(fin[i]==req)
			return 1;
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    int len = s.length();
    int min = 1;
    int max = len/2 +1;

    while(max-min>1)
    {
    	int mid = (min + max) /2;
    	int i = check(mid,s);
    	if(i==1)
    		max = mid;
    	else
    		min = mid;
    }
    if(check(min,s))
    {
    	cout<<min<<endl;
    }
    else
    {
    	cout<<max<<endl;
    }
    return 0;
}