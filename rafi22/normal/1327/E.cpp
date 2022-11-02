    #include <iostream>
     
    using namespace std;
     
     long long power_modulo_fast(long long a, long long b, long long m)
    {
        long long res=1;
        while(b>0)
        {
            if(b&1) res=(a*res)%m;
            a=(a*a)%m;
            b/=2;
        }
     
        return res;
    }
     
    long long silnia[200007];
     
    int main()
    {
     
        long long n,wyn;
        long long mod=998244353;
        cin>>n;
        silnia[1]=1;
        silnia[0]=1;
        for(int i=2;i<=n;i++)
        {
            silnia[i]=(silnia[i-1]*i)%mod;
        }
        for(int i=1;i<=n;i++)
        {
            wyn=10;
            if(n-i>0)
            {
                //cout<<'a';
                wyn*=(2*9*power_modulo_fast(10,max((long long)0,n-i-1),mod))%mod;
                wyn%=mod;
            }
            wyn+=(max((long long)0,n-1-i)*(9*9*power_modulo_fast(10,max((long long)0,n-i-1),mod)))%mod;
            wyn%=mod;
            cout<<wyn<<" ";
     
        }
       /* int wyn1=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int l=0;l<10;l++)
                {
                    if(i!=j)
                    {
                        cout<<i<<j<<l<<endl;
                        wyn1++;
                    }
                    if(j!=i&&j!=l)
                    {
                        cout<<i<<j<<l<<endl;
                        wyn1++;
                    }
                    if(j!=l)
                    {
                        cout<<i<<j<<l<<endl;
                        wyn1++;
                    }
                }
            }
        }
        cout<<wyn1<<endl;*/
        return 0;
    }