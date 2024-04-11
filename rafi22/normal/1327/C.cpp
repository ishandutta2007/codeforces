    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int n,m,k,a,b;
        cin>>n>>m>>k;
        for(int i=0;i<2*k;i++)
        {
            cin>>a>>b;
        }
        cout<<n+m+n*m-3<<endl;
        for(int i=1;i<n;i++) cout<<'D';
        for(int i=1;i<m;i++) cout<<'L';
        for(int i=0;i<n/2;i++)
        {
            for(int j=1;j<m;j++)
            {
                cout<<'R';
            }
            cout<<'U';
            for(int j=1;j<m;j++)
            {
                cout<<'L';
            }
            if(n%2==0)
            {
                if(i!=n/2-1) cout<<'U';
            }
            else
            {
                cout<<'U';
            }
        }
        if(n%2==1) for(int i=1;i<m;i++) cout<<'R';
        return 0;
    }