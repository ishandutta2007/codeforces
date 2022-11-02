    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        long long t,n,k,act;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n>>k;
            act=n*(n-1)/2;
     
            for(int i=0;i<n;i++)
            {
                act-=n-i-1;
                //cout<<act<<endl;
                if(k>act)
                {
                    cout<<'b';
                    for(int j=0;j<n-(k-act-1)-i-2;j++) cout<<'a';
                    cout<<'b';
                    for(int j=0;j<k-act-1;j++) cout<<'a';
                    break;
                    break;
                }
                else
                {
                    cout<<'a';
     
                }
     
     
            }
            cout<<endl;
        }
        return 0;
    }