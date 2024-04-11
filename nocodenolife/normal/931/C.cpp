#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	if(a>b)
		return b;
	return a;
}

int mod(int a)
{
	if(a>0)
		return a;
	return a*-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    
    int arr[5] = {0};
    arr[2] = 1;


    for(int i=1;i<n;i++)
    {
    	int s;
    	cin>>s;
    	arr[s-k+2]++;
    }
    int i;
    int count;
    for(int f=0;f<5;f++)
    {
    	if(arr[f]!=0)
    	{
    		i=f;
    		break;
    	}
    }
    //to use i,i+1,i+2
    if(arr[i+2]==0)
    {
    	cout<<n<<endl;
    	for(int a=0;a<arr[i];a++)
    	{
    		cout<<k+i-2<<" ";
    	}
    	for(int a=0;a<arr[i+1];a++)
    	{
    		cout<<k+i-1<<" ";
    	}
    	return 0;
    }

    int answer1 = arr[i]+arr[i+2] + (arr[i+1]%2);
    int answer2 = arr[i+1] + mod(arr[i] - arr[i+2]);

    if(answer1>answer2)
    {
    	cout<<answer2<<endl;
    	int c = min(arr[i],arr[i+2]);
    	arr[i+1] += 2 * c;
    	arr[i] -= c;
    	arr[i+2] -= c;
    }
    else
    {
    	cout<<answer1<<endl;
    	int c = arr[i+1]/2;
    	arr[i]+=c;
    	arr[i+2]+=c;
    	arr[i+1] -= 2*c;
    }
    for(int a=0;a<arr[i];a++)
    {
    	cout<<k+i-2<<" ";
    }
    for(int a=0;a<arr[i+1];a++)
    {
    	cout<<k+i-1<<" ";
    }
    for(int a=0;a<arr[i+2];a++)
    {
    	cout<<k+i<<" ";
    }

    return 0;
}