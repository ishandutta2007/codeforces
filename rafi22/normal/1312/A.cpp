    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,a,b;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>a>>b;
            if(a%b==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        return 0;
    }