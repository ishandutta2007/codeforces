    #include <iostream>
     
    using namespace std;
     
    int main()
    {
       long long n,a,b;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            if(a>=b*b)
            {
                if(b%2==0)
                {
                    if(a%2==0) cout<<"YES"<<endl;
                    else  cout<<"NO"<<endl;
                }
                else
                {
                    if(a%2==1) cout<<"YES"<<endl;
                    else  cout<<"NO"<<endl;
                }
            }
            else cout<<"NO"<<endl;
     
        }
        return 0;
    }