# include <iostream>
using namespace std;

char composite[3162278];

int main()
{   
    for(long long i=2;i<3162278;i++)
    {
        if(composite[i])continue;
        for(long long j=i*i;j<3162278;j+=i)
            composite[j]=1;
    }
    
    long long N;
    cin>>N;
    
    if(N==1)
    {
        cout<<1<<endl<<0<<endl;
        return 0;
    }
    
    int numfac=0;long long temp=N;
    for(long long i=2;i*i<=N;i++)
    {
        if(composite[i])continue;
        while(temp%i==0)
        {
            temp/=i,numfac++;
            if(numfac==2&&temp>1)
            {
                cout<<1<<endl<<N/temp<<endl;
                return 0;
            }
        }
    }
    
    if(numfac==0)cout<<1<<endl<<0<<endl;
    else cout<<2<<endl;
    
    return 0;
}