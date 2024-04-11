#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,x,a,p=0,np=0;
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0) p++;
            else np++;
        }
        if(np%2==0) np--;
        if(np>0&&p+np>=x)
        {
        	if(x%2==0&&p==0) cout<<"No"<<endl;
        	else cout<<"Yes"<<endl;
 
        }
        else cout<<"No"<<endl;
    }
    return 0;
}