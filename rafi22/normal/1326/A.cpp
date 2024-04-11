    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,a,b;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>a;
            if(a==1) cout<<-1<<endl;
            else
            {
                if((a-1)%3==0)
                {
                    cout<<3;
                    for(int j=0;j<a-2;j++) cout<<2;
                    cout<<3;
                }
                else
                {
                    for(int j=0;j<a-1;j++) cout<<2;
                    cout<<3;
                }
                cout<<endl;
            }
        }
        return 0;
    }