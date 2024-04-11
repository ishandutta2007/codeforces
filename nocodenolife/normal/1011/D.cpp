#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        fflush(stdout);
        cout<<m<<endl;
        int ans;
        cin>>ans;
        if(ans==0)
            return 0;
        else
        {
            if(ans == 1)
                arr[i]=0;
            else
                arr[i]=1;
        }
    }
    int min = 1;
    int max = m;
    int counter = 0;
    while(max-min>1)
    {
        int mid = (min+max)/2;
        fflush(stdout);
        cout<<mid<<endl;
        int ans;
        cin>>ans;
        if(ans==0)
            return 0;
        if(arr[counter]==0)
            ans *= -1;
        
        if(ans==1)
            min = mid+1;
        else
            max = mid-1;
        counter = (counter+1)%n;
    }
    
    fflush(stdout);
    cout<<min<<endl;
    int ans;
    cin>>ans;
    if(ans==0)
        return 0;
    fflush(stdout);
    cout<<max<<endl;
    cin>>ans;
    if(ans==0)
        return 0;
    
    return 0;
}