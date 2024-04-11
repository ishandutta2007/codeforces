#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    char col[] = {'p','g','b','o','r','y'};
    int colo[6] = {0};
    for(int i=0;i<n;i++)
    {
    	string x;
    	cin>>x;
    	for(int i=0;i<6;i++)
    	{
    		if(col[i]==x[0])
    		{
    			colo[i]=1;
    			break;
    		}
    	}
    }
    cout<<6-n<<endl;
    if(colo[0]==0)
    	cout<<"Power"<<endl;
    if(colo[1]==0)
    	cout<<"Time"<<endl;
    if(colo[2]==0)
    	cout<<"Space"<<endl;
    if(colo[3]==0)
    	cout<<"Soul"<<endl;
    if(colo[4]==0)
    	cout<<"Reality"<<endl;
    if(colo[5]==0)
    	cout<<"Mind"<<endl;

    return 0;
}