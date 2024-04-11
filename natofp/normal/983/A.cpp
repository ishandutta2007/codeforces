#include <iostream>

using namespace std;

long long int NWD(long long int a,long long int b)
{
    long long int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    long long int p,q,b;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {


        cin>>p>>q>>b;


        q/=NWD(p,q);

            b=NWD(b,q);
            while(b!=1)
            {
                while(q%b==0) q/=b;
                b=NWD(q,b);
            }


        if (q == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
}

    return 0;
}