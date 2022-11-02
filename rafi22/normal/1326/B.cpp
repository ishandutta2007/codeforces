    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int n,a,maxi=0;
        cin>>n;
        cin>>a;
        cout<<a<<" ";
        maxi=a;
        for(int i=0;i<n-1;i++)
        {
            cin>>a;
            cout<<a+maxi<<" ";
            maxi=max(maxi,a+maxi);
        }
        return 0;
    }