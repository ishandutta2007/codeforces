#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sti(string liczba)
{
    int x=0;
    int n=liczba.length();
    int a=1;
    for(int i=n-1;i>=0;i--)
    {

        x+=((liczba[i]-48))*a;
        a*=10;


    }

    return x;
}

int kwadraty[44721];

bool czyjest(int x)
{
    int a=0;
    int b=44720;
    for(;;)
    {
        int srodek=(a+b)/2;
        if(kwadraty[srodek]==x) return true;
        if(a==b) return false;
        else if (kwadraty[srodek]<x)
        {
            a=srodek+1;
        }
        else
        {
            b=srodek;
        }
    }
}

int main()
{
    for(int i=0;i<44721;i++)
    {
        kwadraty[i]=(i+1)*(i+1);
    }
    string wyraz;
    cin>>wyraz;
    int n=wyraz.length();

    int naj=100;
    for(int i=1;i<1<<n;i++)
    {
        string liczba="";
        bool prawda=false;
        for(int j=0;j<n;j++)
        {
            if(i & 1<<j)
            {
                liczba+=wyraz[j];
                prawda=true;
            }


        }
        if(prawda)
        {

         if(liczba[0]!='0')
        {

            int x=sti(liczba);

            if(czyjest(x) )
            {

                if(naj>n-liczba.length())
                {
                    naj=n-liczba.length();

                }
            }

        }
        }

    }
    if(naj==100) cout<<"-1";
    else cout<<naj;







    return 0;
}