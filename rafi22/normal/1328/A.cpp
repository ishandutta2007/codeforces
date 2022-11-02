    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,a,b;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>a>>b;
            if(a%b==0) cout<<0<<'\n';
            else cout<<a-a%b+b-a<<'\n';
        }
     
        return 0;
    }