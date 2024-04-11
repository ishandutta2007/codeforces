    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,n,a,b,prea,preb;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            prea=0;
            preb=0;
            bool ok=1;
            for(int j=0;j<n;j++)
            {
                cin>>a>>b;
                if(b>a) ok=0;
                if(a<prea||b<preb) ok=0;
                if(a-prea<b-preb) ok=0;
                prea=a;
                preb=b;
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        return 0;
    }