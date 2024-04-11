    #include <iostream>
     
    using namespace std;
     
    bool was[207];
     
    int main()
    {
         int t,n,v,a;
         cin>>t;
         for(int i=0;i<t;i++)
         {
            cin>>n>>v;
            for(int j=0;j<=200;j++)
            {
                was[j]=0;
            }
            for(int j=0;j<n;j++)
            {
                cin>>a;
                was[a]=1;
            }
            for(int j=1;j<=201;j++)
            {
                if(was[j])
                {
     
                }
                else
                {
                    if(v==0)
                    {
                        cout<<j-1<<endl;
                        break;
                    }
                    v--;
                }
            }
     
         }
        return 0;
    }